//
// Created by joni on 12/01/2020.
//

#include <mutex>
#include "StompConnectionProtocal.h"

StompConnectionProtocal::StompConnectionProtocal(User* user,ConnectionHandler* connectionHandler) {
    this->terminate= false;
    this->activeuser=user;
    this->connectionHandler=connectionHandler;
}
void StompConnectionProtocal::setConnectionHandler(ConnectionHandler *connect) {
    connectionHandler=connect;
}


void StompConnectionProtocal::run() {
    std::string spliter = ":";
    while (!terminate) {

        std::string answer;
        // Get back an answer: by using the expected number of bytes (len bytes + newline delimiter)
        // We could also use: connectionHandler.getline(answer) and then get the answer without the newline char at the end
        if (!connectionHandler->getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
        }
        cout << answer << endl;
//        stringstream split(answer);
//        string token;
//        vector<string> splitLines;
//        while(getline(split,token,'\n'))
//        splitLines.push_back(token);
        vector<string> splitLines=this->split(answer,'\n');
        string stompCommand=splitLines[0];
        for(string s: splitLines)
            cout<< s << endl;
        // A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
        // we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        if (stompCommand=="CONNECTED")
        {
            activeuser->setActive(true);
            activeuser->setawait(false);
        }
       else if(stompCommand=="RECEIPT")
        {
            vector<string> reciteid=this->split(splitLines.at(1),':');
            int reicitid=stoi(reciteid.at(1));
            string toProforam=activeuser->getRecitebyId(reicitid);
            vector<string> frameLines=this->split(toProforam,'\n');
            if(frameLines.at(0).compare("UNSUBSCRIBE")==0)
            {
                string idrstr=toProforam.substr(toProforam.find(':')+1);
                idrstr=idrstr.substr(0,idrstr.find('\n')-1);
                int subId=  stoi(idrstr);
                activeuser->unsubsribe(subId);
                cout << "Unsubsribed successfil" << endl;


            } else if (frameLines.at(0).compare("SUBSCRIBE")==0)
            {
                vector<string> secondHeader=this->split(frameLines.at(1),':');
                string topic=secondHeader.at(1);
                secondHeader=this->split(frameLines.at(2),':');
                int subId=  stoi(secondHeader.at(1));
                activeuser->subsribe(topic,subId);
                cout << "Subsribed successfil" << endl;

            }
            else if (frameLines.at(0).compare("DISCONNECT")==0)
            {
                terminate= true;
                delete this->activeuser;

            }


        } else if(splitLines.at(0).compare("MESSAGE")==0)
        {
            answer=answer.substr(answer.find(':')+1);
            int deletpoint=answer.find('\n');
            string subidstr=answer.substr(0,deletpoint-1);
            int subid=stoi(subidstr);
            answer=answer.substr(deletpoint+1);
            answer=answer.substr(answer.find('\n')+1);
            string topic =answer.substr(answer.find(':')+1,answer.find('\n')-1);
            answer=answer.substr(answer.find('\n')+1);
            answer=answer.substr(answer.find('\n')+1);
            string body=answer.substr(0,answer.find('\0')-1);
            if (body.find("wish to borrow") != string::npos) // bo wishes to boorow dune
            {
                int i = body.length() - 1; // last character
                while (i != 0 && !isspace(body[i]))
                    --i;
                string book = body.substr(i+1);

                 if(body.substr(0,body.find(' ')).compare(activeuser->getUsername())==0)
                     activeuser->addbooksWantingToborrow(topic,book);

                 else if (activeuser->containsbook(topic,book)||activeuser->hasBorrowedbook(topic,book)){
                     Send ans(topic,activeuser->getUsername()+" has "+book);
                     this->send(ans.toString());
                 }

            }
            else if (body.find("has") != string::npos)//bob has book dune
            {
                int i = body.length() - 1; // last character
                while (i != 0 && !isspace(body[i]))
                    --i;
                string book = body.substr(i+1);
                if(activeuser->hasbooksWantingToborrow(topic,book))
                {
                    string userToTakeFrom=body.substr(0,body.find(' '));
                    activeuser->addBorrowedbook(topic,book,userToTakeFrom);
                    Send ans(topic,"Taking "+book+" from "+userToTakeFrom);
                    this->send(ans.toString());
                }
            }
            else if (body.find("Taking") != string::npos) //Taking Dune from john
            {
                int i = body.length() - 1; // last character
                while (i != 0 && !isspace(body[i]))
                    --i;
                string username = body.substr(i+1);
                if(username==activeuser->getUsername())
                {
                    string book=body.substr(body.find(' ')+1);
                    book=book.substr(0,body.find(' ')-1);
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
            else if (body.find("Returning") != string::npos)//Returning Dune to john
            {
                int i = body.length() - 1; // last character
                while (i != 0 && !isspace(body[i]))
                    --i;
                string username = body.substr(i+1);
                if(username==activeuser->getUsername())
                {
                    string book=body.substr(body.find(' ')+1);
                    book=book.substr(0,body.find(' ')-1);
                    activeuser->removeBookRentedOut(topic,book);
                }

            }
            else if (body.find("Book status") != string::npos)//Book status
            {
                    Send ans(topic,activeuser->getUsername()+":"+activeuser->printBooksInTopic(topic));
                    this->send(ans.toString());
            }
       }



//        size_t pos = 0;
//        std::string token;
//        while ((pos = answer.find(spliter)) != std::string::npos) {
//            token = s.substr(0, pos);
//            std::cout << token << std::endl;
//            answer.erase(0, pos + spliter.length());
//        }
//        std::cout << answer << std::endl;
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
    if (!connectionHandler->sendLine(frame)) {
        std::cout << "Disconnected. Exiting...\n" << std::endl;
        this->terminate= true;
        return false;
    }
    return true;
}

