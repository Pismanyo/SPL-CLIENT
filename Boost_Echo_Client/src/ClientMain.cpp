#include "connectionHandler.h"
#include "StompConnectionProtocal.h"
#include "UserCommands.h"

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    bool finalTerminate=false;
    User* activeUser;
    StompConnectionProtocal *stomp = nullptr;
    connectionHandler *connectionhandler = nullptr;
    UserCommands *usercommands= nullptr;
   while(!finalTerminate) {
       string answer1;
       int counter;
       string inputs[5];
       getline(cin, answer1);
       string word;
       counter = 0;
       std::stringstream iss(answer1);
       while (iss >> word && counter < 6)
           inputs[counter++] = word;
       if (inputs[0].compare("login") == 0 && !finalTerminate) {
           stomp = nullptr;
           cout << "trying to connect" << endl;
           activeUser = new User();
           string host = inputs[1].substr(0, inputs[1].find(':'));
           string portstr = inputs[1].substr(inputs[1].find(':') + 1);
           char char_array[portstr.length() + 1];
           strcpy(char_array, portstr.c_str());
           short port = atoi(char_array);
           cout << port << endl;
           connectionhandler = new connectionHandler(host, port);
           if (!connectionhandler->connect()) {
               stomp = nullptr;
               std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
           } else {
               Connect ans("1.2", host, inputs[2], inputs[3]);
               activeUser->setuserandpass(inputs[2], inputs[3]);
               stomp = new StompConnectionProtocal(activeUser, connectionhandler);
               usercommands = new UserCommands(activeUser, stomp, ans);
               std::thread th2(&StompConnectionProtocal::run, stomp);
               std::thread th1(&UserCommands::run, usercommands);
               th1.join();
               th2.join();
               finalTerminate = true;
           }
       }
   }
    delete activeUser;
    delete stomp;
    delete connectionhandler;
    delete usercommands;

    return 0;
}
