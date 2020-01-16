#include <stdlib.h>
#include <connectionHandler.h>
#include <StompConnectionProtocal.h>
#include "UserCommands.h"

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    bool finalTerminate=false;
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
           cout << "trying to connect" << endl;
           User *activeuser = new User();
           string host = inputs[1].substr(0,inputs[1].find(':'));
           string portstr = inputs[1].substr(inputs[1].find(':') + 1);
           char char_array[portstr.length() + 1];
           strcpy(char_array, portstr.c_str());
           short port = atoi(char_array);
           cout << port << endl;
           ConnectionHandler *connectionHandler = new ConnectionHandler(host, port);
           if (!connectionHandler->connect()) {
               std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
           } else {
               Connect ans("1.2", host, inputs[2], inputs[3]);
               activeuser->setuserandpass(inputs[2], inputs[3]);
               StompConnectionProtocal *stomp = new StompConnectionProtocal(activeuser, connectionHandler);
               std::thread th2(&StompConnectionProtocal::run, stomp);
               UserCommands usercommands(activeuser,stomp, ans);
               std::thread th1(&UserCommands::run, usercommands);

               th1.join();
               th2.join();
               delete(connectionHandler);
               delete(activeuser);
               delete(stomp);
               if(usercommands.getFinalTerminate())
                   finalTerminate= true;
           }

       }
   }

//    std::string host = argv[1];
//    short port = atoi(argv[2]);
//
//    ConnectionHandler connectionHandler(host, port);
//    if (!connectionHandler.connect()) {
//        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
//        return 1;
//    }
//
//	//From here we will see the rest of the ehco client implementation:
//    while (1) {
//        const short bufsize = 1024;
//        char buf[bufsize];
//        std::cin.getline(buf, bufsize);
//		std::string line(buf);
//		int len=line.length();
//        if (!connectionHandler.sendLine(line)) {
//            std::cout << "Disconnected. Exiting...\n" << std::endl;
//            break;
//        }
//		// connectionHandler.sendLine(line) appends '\n' to the message. Therefor we send len+1 bytes.
//        std::cout << "Sent " << len+1 << " bytes to server" << std::endl;
//
//
//        // We can use one of three options to read data from the server:
//        // 1. Read a fixed number of characters
//        // 2. Read a line (up to the newline character using the getline() buffered reader
//        // 3. Read up to the null character
//        std::string answer;
//        // Get back an answer: by using the expected number of bytes (len bytes + newline delimiter)
//        // We could also use: connectionHandler.getline(answer) and then get the answer without the newline char at the end
//        if (!connectionHandler.getLine(answer)) {
//            std::cout << "Disconnected. Exiting...\n" << std::endl;
//            break;
//        }
//
//		len=answer.length();
//		// A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
//		// we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
//        answer.resize(len-1);
//        std::cout << "Reply: " << answer << " " << len << " bytes " << std::endl << std::endl;
//        if (answer == "bye") {
//            std::cout << "Exiting...\n" << std::endl;
//            break;
      //  }
   // }
    return 0;
}
