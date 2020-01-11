

#include <include/Frame.h>

using namespace std;

Frame::Frame(string stompCommand, vector<string> headersVector, string frameBody):stompCommand(std::move(stompCommand)),headersVector(std::move(headersVector)),frameBody(std::move(frameBody)) {}

Frame::~Frame() = default;



