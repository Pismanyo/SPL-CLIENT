
#include "Frame.h"

using namespace std;

Frame::~Frame() = default;

string Connect::toString() {
    string a="CONNECT";
    a+='\n';
    a+="accept-version:";
    a+=this->version;
    a+='\n';
    a+="host:";
    a+=this->host;
    a+='\n';
    a+="login:";
    a+=this->username;
    a+='\n';
    a+="passcode:";
    a+=this->password;
    a+='\n';
    a+='\n';
    return a;
}

Connect::Connect(string version, string host, string username, string password) : version(version),username(username)
,password(password),host(host){}

Send::Send(string topic, string message): topic(topic),message(message) {}

string Send::toString() {
    string a="SEND";
    a+='\n';
    a+="destination:";
    a+=this->topic;
    a+='\n';
    a+='\n';
    a+=this->message;
    a+='\n';
    return a;
}

Subscribe::Subscribe(string topic, int id, int recite): topic(topic),id(id),recite(recite) {}

string Subscribe::toString() {
    string a="SUBSCRIBE";
    a+='\n';
    a+="destination:";
    a+=this->topic;
    a+='\n';
    a+="id:";
    a+=std::to_string(this->id);
    a+='\n';
    a+="receipt:";
    a+=std::to_string(this->recite);
    a+='\n';
    a+='\n';
    return a;
}

Unsubscribe::Unsubscribe( int id): id(id) {}

string Unsubscribe::toString() {
    string a="UNSUBSCRIBE";
    a+='\n';
    a+="id:";
    a+=std::to_string(this->id);
    a+='\n';
    a+='\n';
    return a;
}

Disconnect::Disconnect(int recite):recite(recite) {}

string Disconnect::toString() {
    string a="DISCONNECT";
    a+='\n';
    a+="receipt:";
    a+=std::to_string(this->recite);
    a+='\n';
    a+='\n';
    return a;
}


