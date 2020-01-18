
#include <mutex>
#include "StompConnectionProtocal.h"

StompConnectionProtocal::StompConnectionProtocal(User* user, connectionHandler* connectionhandler):toTerminate(false) {
    this->activeuser=user;
    this->connectionhandler=connectionhandler;
}

/**
 * Receives frames from the client and communicates with the servers and passes and handles frames from the server.
 */
void StompConnectionProtocal::run() {
    std::string spliter = ":";
    while (!toTerminate) {
        std::string answer;
        if (!connectionhandler->getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            activeuser->setTerminate(true);
        } else {
            cout << answer << endl;

            vector<string> splitLines = this->split(answer, '\n');
            string stompCommand = splitLines[0];
            if (stompCommand == "ERROR") {
                activeuser->setTerminate(true);

            } else if (stompCommand == "CONNECTED") {
                activeuser->setActive(true);
                activeuser->setawait(false);
                std::cout << "Login successful\n" << std::endl;
            } else if (stompCommand == "RECEIPT") {
                this->gotReciteMessage(splitLines);
            } else if (stompCommand == "MESSAGE") {
                this->gotMessageMessage(splitLines);
            }
        }
        toTerminate = activeuser->getTerminate();
    }
}
/**
 * Splits a string into a desired way.
 * @param tosplite A message to split.
 * @param delimiter A delimiter to split the message by.
 * @return A vector of split strings.
 */
vector<string> StompConnectionProtocal::split(string tosplite,char delimiter)
{
    stringstream split(tosplite);
    string token;
    vector<string> ans;
    while(getline(split,token,delimiter))
        ans.push_back(token);
    return ans;

}

/**
 * Sends a frame to the server.
 * @param frame A frame to be sent to the server
 * @return True if the frame was sent and false otherwise.
 */
bool StompConnectionProtocal::send(string frame) {
    std::lock_guard<std::mutex> lock (_mutex);
    if (!connectionhandler->sendLine(frame)) {
        std::cout << "Disconnected. Exiting...\n" << std::endl;
        activeuser->setTerminate(true);
        return false;
    }
    return true;
}

/**
 * Handles the case of a receipt frame received by the server.
 * @param splitLines A frame to analyze.
 */
void StompConnectionProtocal:: gotReciteMessage(vector<string> splitLines)
{
    vector<string> reciteid=this->split(splitLines.at(1),':');
    int reicitid=stoi(reciteid.at(1));
    string toProforam=activeuser->getRecitebyId(reicitid);
    vector<string> frameLines=this->split(toProforam,'\n');
    if(frameLines.at(0).compare("UNSUBSCRIBE")==0)
    {
        vector<string> recitLineSplite=this->split(frameLines.at(1),':');
        int subId=  stoi(recitLineSplite.at(1));
        string topic=activeuser->unsubsribe(subId);
        cout << "Exited club "+ topic<< endl;


    }
    else if (frameLines.at(0).compare("SUBSCRIBE")==0)
    {
        vector<string> secondHeader=this->split(frameLines.at(1),':');
        string topic=secondHeader.at(1);
        secondHeader=this->split(frameLines.at(2),':');
        int subId=  stoi(secondHeader.at(1));
        activeuser->subsribe(topic,subId);
        cout << "Joined club "+topic << endl;

    }
    else if (splitLines.at(0)=="DISCONNECT")
    {
         this->activeuser->setTerminate(true);
    }

}
/**
 * Handles everything related to asking for book status and book borrow and returning.
 * @param splitLines A message to turn into a frame and send to the server.
 */
void StompConnectionProtocal:: gotMessageMessage(vector<string> splitLines){

    string topic;
    for(int i=1;i<=3;i++) {
        vector<string>temp =this->split(splitLines.at(i),':');
        if(temp.at(0)=="subscription")
             stoi(temp.at(1));
        if(temp.at(0)=="destination")
             topic =temp.at(1);
    }
    
int splitSize = splitLines.size();
    string body="";
    for (int i=5;i<splitSize;i++)
    {
        if(splitLines.at(i)!="")
            body=body+splitLines.at(i)+"\n";
    }
    body=body.substr(0,body.length()-1);
    vector<string> bodyWords = this->split(body,' ');
    int bodySize=bodyWords.size();
    if (bodySize>=5&&body.find("wish to borrow") != string::npos) // bo wishes to borrow dune
    {
        this->WishtoBorrow(bodyWords,topic);

    }
     else if (bodySize>=6&&bodyWords.at(1)==("has")&&bodyWords.at(2)=="added")//bob has added the book dune
    {
        this->HasAdded(bodyWords,topic);
    }
    else if (bodySize>=3&&bodyWords.at(1)==("has"))//bob has dune
    {
        this->HasBook(bodyWords,topic);
    }
    else if (bodySize>=4&&bodyWords.at(0)==("Taking")) //Taking Dune from john
    {

        string username =bodyWords.at(bodySize-1);
        if(username==activeuser->getUsername())
        {
            string book="";
            for(int i=1;i<(bodySize-2);i++)
            {
                book=book+bodyWords.at(i)+" ";
            }
            book=book.substr(0,book.length()-1);
            if(this->activeuser->containsbook(topic,book))
            {
                this->activeuser->rentBook(topic,book);
            }
            if(this->activeuser->hasBorrowedbook(topic,book))
            {
                this->activeuser->rentBorrowedBook(topic,book);
            }
        }

    }
    else if (bodySize>=4&&bodyWords.at(0)==("Returning"))//Returning Dune to john
    {

        string username = bodyWords.at(bodySize-1);
        if(username==activeuser->getUsername())
        {
            string book="";
            for(int i=1;i<(bodySize-2);i++)
            {
                book=book+bodyWords.at(i)+" ";
            }
            book=book.substr(0,book.length()-1);
            activeuser->removeBookRentedOut(topic,book);
        }

    }
    else if (bodySize>=2&&bodyWords.at(0)=="book"&&bodyWords.at(1)=="status")//Book status
    {
        Send ans(topic,activeuser->getUsername()+":"+activeuser->printBooksInTopic(topic));
        this->send(ans.toString());
    }
}
/**
 * Creates a send frame for a book a client wants to borrow.
 * @param bodyWords The meesage to turn into a send frame.
 * @param topic A topic we search the books locations at.
 */
void StompConnectionProtocal:: WishtoBorrow(vector<string> bodyWords,string topic)
{
    int bodySize=bodyWords.size();
    string book="";
    for(int i=4;i<bodySize;i++)
    {
        book=book+bodyWords.at(i)+" ";
    }
    book=book.substr(0,book.length()-1);
    if(bodyWords.at(0).compare(activeuser->getUsername())==0)
        activeuser->addbooksWantingToborrow(topic,book);

    else if (activeuser->containsbook(topic,book)||activeuser->hasBorrowedbook(topic,book)){
        Send ans(topic,activeuser->getUsername()+" has "+book);
        this->send(ans.toString());
    }
}
void StompConnectionProtocal:: HasBook(vector<string> bodyWords,string topic)
{
    int bodySize=bodyWords.size();
    string book="";
    for(int i=2;i<bodySize;i++)
        book=book+bodyWords.at(i)+" ";
    book=book.substr(0,book.length()-1);
    if(bodyWords.at(0)!=activeuser->getUsername()&&activeuser->hasbooksWantingToborrow(topic,book))
    {
        string userToTakeFrom=bodyWords.at(0);
        activeuser->addBorrowedbook(topic,book,userToTakeFrom);
        Send ans(topic,"Taking "+book+" from "+userToTakeFrom);
        this->send(ans.toString());
    }
}
void StompConnectionProtocal:: HasAdded(vector<string> bodyWords,string topic)
{
    int bodySize = bodyWords.size();
    string book="";
    for(int i=5;i<bodySize;i++)
    {
        book=book+bodyWords.at(i)+" ";
    }
    book=book.substr(0,book.length()-1);
    if(activeuser->hasbooksWantingToborrow(topic,book))
    {
        string userToTakeFrom=bodyWords.at(0);
        activeuser->addBorrowedbook(topic,book,userToTakeFrom);
        Send ans(topic,"Taking "+book+" from "+userToTakeFrom);
        this->send(ans.toString());
    }

}



