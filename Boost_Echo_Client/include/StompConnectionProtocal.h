//
// Created by joni on 12/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_STOMPCONNECTIONPROTOCAL_H
#define BOOST_ECHO_CLIENT_STOMPCONNECTIONPROTOCAL_H

#include <mutex>

#include "User.h"

class StompConnectionProtocal {
private:
    User* activeuser;
    bool terminate;
    mutex _mutex;
    ConnectionHandler* connectionHandler;
public:
    StompConnectionProtocal(User* user,ConnectionHandler* connectionHandler);
    void run();
    bool send(string frame);
    void setConnectionHandler (ConnectionHandler* connect);

    vector<string> split(string tosplite, char denimator);

    void gotReciteMessage();

    void gotReciteMessage(vector<string> splitLines);

    void gotMessageMessage(vector<string> splitLines);
};


#endif //BOOST_ECHO_CLIENT_STOMPCONNECTIONPROTOCAL_H
