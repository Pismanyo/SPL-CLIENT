
#ifndef BOOST_ECHO_CLIENT_STOMPCONNECTIONPROTOCAL_H
#define BOOST_ECHO_CLIENT_STOMPCONNECTIONPROTOCAL_H

#include <mutex>

#include "User.h"

class StompConnectionProtocal {
private:
    User* activeuser{};
    mutex _mutex{};
    connectionHandler* connectionhandler{};
    bool toTerminate= false;
public:
    StompConnectionProtocal(User* user, connectionHandler* connectionhandler);
    void run();
    bool send(string frame);
    vector<string> split(string tosplite, char denimator);
    void gotReciteMessage(vector<string> splitLines);
    void gotMessageMessage(vector<string> splitLines);
    void WishtoBorrow(vector<string> bodyWords, string topic);
    void HasAdded(vector<string> bodyWords, string topic);
    void HasBook(vector<string> bodyWords, string topic);
};


#endif
