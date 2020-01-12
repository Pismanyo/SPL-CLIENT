

#ifndef BOOST_ECHO_CLIENT_FRAME_H
#define BOOST_ECHO_CLIENT_FRAME_H

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Frame {
private:


public:
    Frame()= default;
    virtual ~Frame();
};


class Connect:public Frame {
private :
    string version;
    string username;
    string password;
    string host;
public:
    Connect(string version,string host,string username,string password);
    virtual string toString();
};
class subscribeFrame : public Frame{};

class Send:public Frame{
private :
    string topic;
    string message;

public:
    Send(string topic,string message);
    virtual string toString();
};

class Subscribe : public Frame{
private :
    string topic;
    int id;
    int recite;
public:
    Subscribe(string topic,int id,int recite);
    virtual string toString();
};

class Unsubscribe : public Frame {
private :
    int id;
public:
    Unsubscribe(int id);
    virtual string toString();
};

class Disconnect : public Frame {
private :
    int recite;
public:
    Disconnect(int recite);
    virtual string toString();
};

#endif //BOOST_ECHO_CLIENT_FRAME_H
