//
// Created by joni on 12/01/2020.
//

#include <mutex>
#include "StompConnectionProtocal.h"

StompConnectionProtocal::StompConnectionProtocal(User* user,ConnectionHandler* connectionHandler) {
//    this->terminate= false;
    this->activeuser=user;
    this->connectionHandler=connectionHandler;
}
void StompConnectionProtocal::setConnectionHandler(ConnectionHandler *connect) {
    connectionHandler=connect;
}


void StompConnectionProtocal::run() {
    std::string spliter = ":";
    while (!activeuser->getTerminate()) {

        std::string answer;
        if (!connectionHandler->getLine(answer)) {
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
    }
}
vector<string> StompConnectionProtocal::split(string tosplite,char denimator)
{
    stringstream split(tosplite);
    string token;
    vector<string> ans;
    while(getline(split,token,denimator))
        ans.push_back(token);
    return ans;

}

bool StompConnectionProtocal::send(string frame) {
    std::lock_guard<std::mutex> lock (_mutex);
//    if(activeuser->getTerminate())
//    {
//        return false;
//    }
    if (!connectionHandler->sendLine(frame)) {
        std::cout << "Disconnected. Exiting...\n" << std::endl;
        activeuser->setTerminate(true);
        return false;
    }
    return true;
}

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

void StompConnectionProtocal:: gotMessageMessage(vector<string> splitLines){

    string topic;
    int subid;
    for(int i=1;i<=3;i++) {
        vector<string>temp =this->split(splitLines.at(i),':');
        if(temp.at(0)=="subscription")
             subid=stoi(temp.at(1));
        if(temp.at(0)=="destination")
             topic =temp.at(1);
    }


    string body="";
    for (int i=5;i<splitLines.size();i++)
    {
        if(splitLines.at(i)!="")
            body=body+splitLines.at(i)+"\n";
    }
    body=body.substr(0,body.length()-1);
    //
    //  cout << "body:"+body << endl;
    vector<string> bodyWords = this->split(body,' ');
    if (bodyWords.size()>=5&&body.find("wish to borrow") != string::npos) // bo wishes to boorow dune
    {
        this->WishtoBorrow(bodyWords,topic);

    }
     else if (bodyWords.size()>=4&&bodyWords.at(0)!=activeuser->getUsername()&&bodyWords.at(1)==("has")&&bodyWords.at(2)=="added")//bob has added dune
    {
        this->HadAdded(bodyWords,topic);
    }
    else if (bodyWords.size()>=3&&bodyWords.at(1)==("has"))//bob has dune
    {
        this->HadBook(bodyWords,topic);
    }
    else if (bodyWords.size()>=4&&bodyWords.at(0)==("Taking")) //Taking Dune from john
    {

        string username =bodyWords.at(bodyWords.size()-1);
        if(username==activeuser->getUsername())
        {
            string book="";
            for(int i=1;i<(bodyWords.size()-2);i++)
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
    else if (bodyWords.size()>=4&&bodyWords.at(0)==("Returning"))//Returning Dune to john
    {

        string username = bodyWords.at(bodyWords.size()-1);
        if(username==activeuser->getUsername())
        {
            string book="";
            for(int i=1;i<(bodyWords.size()-2);i++)
            {
                book=book+bodyWords.at(i)+" ";
            }
            book=book.substr(0,book.length()-1);
            activeuser->removeBookRentedOut(topic,book);
        }

    }
    else if (bodyWords.size()>=2&&bodyWords.at(0)=="book"&&bodyWords.at(1)=="status")//Book status
    {
        Send ans(topic,activeuser->getUsername()+":"+activeuser->printBooksInTopic(topic));
        this->send(ans.toString());
    }
}
void StompConnectionProtocal:: WishtoBorrow(vector<string> bodyWords,string topic)
{
    string book="";
    for(int i=4;i<bodyWords.size();i++)
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
void StompConnectionProtocal:: HadBook(vector<string> bodyWords,string topic)
{
    string book="";
    for(int i=2;i<bodyWords.size();i++)
        book=book+bodyWords.at(i)+" ";
    book=book.substr(0,book.length()-1);
    cout<<book<<endl;
    if(activeuser->hasbooksWantingToborrow(topic,book))
    {
        string userToTakeFrom=bodyWords.at(0);
        activeuser->addBorrowedbook(topic,book,userToTakeFrom);
        Send ans(topic,"Taking "+book+" from "+userToTakeFrom);
        this->send(ans.toString());
    }
}
void StompConnectionProtocal:: HadAdded(vector<string> bodyWords,string topic)
{
    string book="";
    for(int i=5;i<bodyWords.size();i++)
    {
        book=book+bodyWords.at(i)+" ";
    }
    book=book.substr(0,book.length()-1);
    //  cout << book<< endl;
    if(activeuser->hasbooksWantingToborrow(topic,book))
    {
        string userToTakeFrom=bodyWords.at(0);
        activeuser->addBorrowedbook(topic,book,userToTakeFrom);
        Send ans(topic,"Taking "+book+" from "+userToTakeFrom);
        this->send(ans.toString());
    }

}



