
#ifndef BOOST_ECHO_CLIENT_STOMPCONNECTIONHANDLER_H
#define BOOST_ECHO_CLIENT_STOMPCONNECTIONHANDLER_H

#include <boost/asio.hpp>
#include <StompMessageProtocol.h>
#include <StompMessageEncoderDecoder.h>
using boost::asio::ip::tcp;

class StompConnectionHandler{
private:
    tcp::socket socket;
    StompMessageEncoderDecoder messageEncDec;
    StompProtocol stompProtocol;

};
#endif //BOOST_ECHO_CLIENT_STOMPCONNECTIONHANDLER_H
