
#ifndef BOOST_ECHO_CLIENT_STOMPMESSAGEENCODERDECODER_H
#define BOOST_ECHO_CLIENT_STOMPMESSAGEENCODERDECODER_H

#include <string>

class StompMessageEncoderDecoder{
public:
    std::string decodeNextByte(char nextByte);
    char* encode(std::string);
};
#endif //BOOST_ECHO_CLIENT_STOMPMESSAGEENCODERDECODER_H
