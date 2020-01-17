#include <stdlib.h>
#include <connectionHandler.h>
#include <StompConnectionProtocal.h>
#include "UserCommands.h"

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    bool finalTerminate=false;
    User* activeUser = nullptr;
    StompConnectionProtocal *stomp = nullptr;
    ConnectionHandler *connectionHandler = nullptr;
   while(!finalTerminate) {
       string answer1;
       int counter;
       string inputs[5];
       bool terminate = false;
       getline(cin, answer1);
       string word;
       counter = 0;
       std::stringstream iss(answer1);
       while (iss >> word && counter < 6)
           inputs[counter++] = word;
       if (inputs[0].compare("login") == 0) {
           stomp = nullptr;
           cout << "trying to connect" << endl;
           activeUser = new User();
           string host = inputs[1].substr(0,inputs[1].find(':'));
           string portstr = inputs[1].substr(inputs[1].find(':') + 1);
           char char_array[portstr.length() + 1];
           strcpy(char_array, portstr.c_str());
           short port = atoi(char_array);
           cout << port << endl;
           connectionHandler = new ConnectionHandler(host, port);
           if (!connectionHandler->connect()) {
               stomp = nullptr;
               std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
           } else {
               Connect ans("1.2", host, inputs[2], inputs[3]);
               activeUser->setuserandpass(inputs[2], inputs[3]);
               stomp = new StompConnectionProtocal(activeUser, connectionHandler);
               UserCommands *usercommands = new UserCommands(activeUser, stomp, ans);
               std::thread th2(&StompConnectionProtocal::run, stomp);
               std::thread th1(&UserCommands::run, usercommands);
               th1.join();
               th2.join();
               if (usercommands->getFinalTerminate()) {
                   finalTerminate = true;
               } else {
//                   connectionHandler->close();
                   delete (activeUser);
                   delete (stomp);
                   delete (usercommands);
                   delete (connectionHandler);

               }

           }
       }
   }
    return 0;
}
