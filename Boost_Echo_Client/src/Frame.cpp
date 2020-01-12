

#include <Frame.h>


using namespace std;

Frame::~Frame() = default;

string Connect::toString() {
    string a="CONNECT";
    a+='\n';
    a+="accept-version:";
    a+=this->version;
    a+="host:";
    a+=this->host;
    a+="login:";
    a+=this->username;
    a+='\n';
    a+="passcode:";
    a+=this->password;
    a+='\n';
    a+='\0';

    return a;
}

Connect::Connect(string version, string host, string username, string password) {
    this->version=version;
    this->username=username;
    this->password=password;
    this->host=host;
}


string Send::toString() {
    string a="SEND";
    a+='\n';
    a+="destination:";
    a+=this->topic;
    a+='\n';
    a+=this->message;
    a+='\n';
    a+='\0';

    return a;
}

Send::Send(string topic, string message) {
 this->topic=topic;
 this->message=message;
}

Subscribe::Subscribe(string topic, int id, int recite) {

}

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
    a+='\0';

    return a;
}

Unsubscribe::Unsubscribe( int id) {

}

string Unsubscribe::toString() {
    string a="UNSUBSCRIBE";
    a+='\n';
    a+="id:";
    a+=std::to_string(this->id);
    a+='\n';
    a+='\0';



    return a;
}

string Disconnect::toString() {
    string a="DISCONNECT";
    a+='\n';
    a+="receipt:";
    a+=std::to_string(this->recite);
    a+='\n';
    a+='\0';



    return a;
}

Disconnect::Disconnect(int recite) {


}

