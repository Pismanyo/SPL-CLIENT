//
// Created by liordu@wincs.cs.bgu.ac.il on 12/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_USERCOMMANDS_H
#define BOOST_ECHO_CLIENT_USERCOMMANDS_H
#include <iostream>
#include <mutex>
#include <thread>
#include <User.h>

class UserCommands{
private:
    User* activeuser;
    StompConnectionProtocal* stomp;
    bool terminate;

public:
    UserCommands (User* active,StompConnectionProtocal* stomp, Connect a);

    void run();
    void login(string version,string username,string password);

    void subsribe(string basicString);
    void logout();
    void status(string topic);

    void unsubsribe(string topic);

    void add(string topic,string book);

    void borrow(string topic,string book);

    void returnCommand(string topic,string book);

    vector<string> split(string tosplite, char denimator);
};


#endif //BOOST_ECHO_CLIENT_USERCOMMANDS_H
