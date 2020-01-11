
#ifndef BOOST_ECHO_CLIENT_STOMPPROTOCOL_H
#define BOOST_ECHO_CLIENT_STOMPPROTOCOL_H

#include <string>
class StompProtocol{
private:
    bool terminate;
public:
    std::string Process(std::string);
    bool shouldTerminate();
    std::string processInput(std::string);
};
#endif //BOOST_ECHO_CLIENT_STOMPPROTOCOL_H
