
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






//
//        if (inputs[0].compare("login") == 0) {
//            if(activeuser->isActive())
//                cout << "Already connected to different user" << endl;
//           else if(activeuser->getawait())
//                cout << "Already connected to different user" << endl;
//            else if(counter!=4)
//                cout << "incorrect input format" << endl;
//            else
//                login(inputs[1],inputs[2],inputs[3]);
//
//        }
//        else if (inputs[0].compare("join") == 0) {
//            if(counter!=2)
//                cout << "incorrect input format" << endl;
//            else if(!activeuser->isActive())
//                cout << "not connected to a user" << endl;
//            else if(activeuser->isSubsribed(inputs[1]))
//                cout << "Already Connected to topic" << endl;
//
//            else
//            {
//                subsribe(inputs[1]);
//            }
//
//        } else if (inputs[0].compare("exit") == 0) {
//
//            if(counter!=2)
//                cout << "incorrect input format" << endl;
//            else if(!activeuser->isActive())
//                cout << "not connected to a user" << endl;
//            else if(!activeuser->isSubsribed(inputs[1]) )//also cheack if s=exit command was already sent
//                    cout << "not connected to a user" << endl;
//            else {
//                unsubsribe(inputs[1]);
//            }
//        }
//        else if (inputs[0].compare("borrow") == 0) {
//
//            if(counter!=2)
//                cout << "incorrect input format" << endl;
//            else if(!activeuser->isActive())
//                cout << "not connected to a user" << endl;
//            else if(!activeuser->isSubsribed(inputs[1])  )
//                cout << "not connected to topic" << endl;
//            else if (!activeuser->containsbook(inputs[1],inputs[2]))
//                cout << "not connected to topic" << endl;
//            else
//            {
//                borrow(inputs[1],inputs[2]);
//            }
//        }
//        else if (inputs[0].compare("logout") == 0) {
//
//            if(counter!=1)
//                cout << "incorrect input format" << endl;
//            else {
//                logout();
//            }
//
//        }
//        else if (inputs[0].compare("add") == 0) {
//
//            if (counter != 3)
//                cout << "incorrect input format" << endl;
//            else if (!activeuser->isActive())
//                cout << "not connected to a user" << endl;
//            else if (!activeuser->isSubsribed(inputs[1]))
//                cout << "not connected to topic" << endl;
//            else if (!activeuser->containsbook(inputs[1],inputs[2]))
//                cout << "not connected to topic" << endl;
//            else {
//                add(inputs[1],inputs[2]);
//            }
//        }
//            else if (inputs[0].compare("return") == 0) {
//
//            if (counter != 3)
//                cout << "incorrect input format" << endl;
//            else if (!activeuser->isActive())
//                cout << "not connected to a user" << endl;
//            else if (!activeuser->isSubsribed(inputs[1]))
//                cout << "not connected to topic" << endl;
//            else if (!activeuser->hasBorrowedbook(inputs[1],inputs[2]))
//                cout << "not connected to topic" << endl;
//            else {
//                returnCommand(inputs[1],inputs[2]);
//            }
//        }
//        else if (inputs[0].compare("status") == 0) {
//
//            if (counter != 2)
//                cout << "incorrect input format" << endl;
//            else if (!activeuser->isActive())
//                cout << "not connected to a user" << endl;
//            else if (!activeuser->isSubsribed(inputs[1]))
//                cout << "not connected to topic" << endl;
//            else {
//                status(inputs[1]);
//            }
//        }
