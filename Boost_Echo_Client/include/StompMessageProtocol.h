
#ifndef BOOST_ECHO_CLIENT_STOMPPROTOCOL_H
#define BOOST_ECHO_CLIENT_STOMPPROTOCOL_H

#include <string>
class StompProtocol{
private:
public:
    std::string Process(std::string);
    bool shouldTerminate();
    std::string processInput(std::string);
};
#endif //BOOST_ECHO_CLIENT_STOMPPROTOCOL_H
