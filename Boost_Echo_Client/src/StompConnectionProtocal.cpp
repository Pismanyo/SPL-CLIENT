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
        // A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
        // we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        string firstline=answer.substr(0,'n');
        if (firstline.compare("CONNECTED"))
        {
            activeuser->setActive(true);
            activeuser->setawait(false);
        }
        if(firstline.compare("RECEIPT"))
        {
            answer=answer.substr(answer.find(':')+1);
            string reciteid=answer.substr(0,answer.find('\n'))
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

bool StompConnectionProtocal::send(string frame) {
    std::lock_guard<std::mutex> lock (_mutex);
    if (!connectionHandler->sendLine(frame)) {
        std::cout << "Disconnected. Exiting...\n" << std::endl;
        this->terminate= true;
        return false;
    }
    return true;
}

