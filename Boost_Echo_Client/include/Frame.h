

#ifndef BOOST_ECHO_CLIENT_FRAME_H
#define BOOST_ECHO_CLIENT_FRAME_H

#include <string>
#include <unordered_map>
#include <vector>

class Frame {
private:
    std::string stompCommand;
    std::vector<std::string> headersVector;
    std::string frameBody;

public:
    Frame(std::string stompCommand,std::vector<std::string> headersVector,std::string frameBody);
    virtual ~Frame();
};

class connectFrame : public Frame{};

class subscribeFrame : public Frame{};

class sendFrame : public Frame{};

class disconnectFrame: public Frame{};
#endif //BOOST_ECHO_CLIENT_FRAME_H
