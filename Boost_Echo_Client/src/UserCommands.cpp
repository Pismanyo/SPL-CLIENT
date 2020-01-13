//
// Created by liordu@wincs.cs.bgu.ac.il on 12/01/2020.
//

#include <cstring>
#include <connectionHandler.h>
#include <Frame.h>
#include <StompConnectionProtocal.h>
#include "UserCommands.h"


void UserCommands::run() {

    string answer1;
    int counter;
    string inputs [5];
    bool terminate= false;
    while (!terminate) {
        getline(cin, answer1);
        string word;
        counter = 0;
        std::stringstream iss(answer1);
        while (iss >> word && counter < 6)
            inputs[counter++] = word;
        if (inputs[0].compare("login") == 0) {
            if (activeuser->isActive())
                cout << "Already connected to different user" << endl;
            else
                login(inputs[1], inputs[2], inputs[3]);
        }

        else if (inputs[0].compare("join") == 0) {
            if(counter!=2)
                cout << "incorrect input format" << endl;
            else if(!activeuser->isActive())
                cout << "not connected to a user" << endl;

            else
            {
                subsribe(inputs[1]);
            }

        } else if (inputs[0].compare("exit") == 0) {

            if(counter!=2)
                cout << "incorrect input format" << endl;
            else if(!activeuser->isActive())
                cout << "not connected to a user" << endl;
            else {
                unsubsribe(inputs[1]);
            }
        }
        else if (inputs[0].compare("borrow") == 0) {

            if(counter!=2)
                cout << "incorrect input format" << endl;
            else if(!activeuser->isActive())
                cout << "not connected to a user" << endl;

            else
            {
                borrow(inputs[1],inputs[2]);
            }
        }
        else if (inputs[0].compare("logout") == 0) {

            if(counter!=1)
                cout << "incorrect input format" << endl;
            else if (!activeuser->isActive())
                cout << "not connected to a user" << endl;
            else {
                logout();
            }

        }
        else if (inputs[0].compare("add") == 0) {

            if (counter != 3)
                cout << "incorrect input format" << endl;
            else if (!activeuser->isActive())
                cout << "not connected to a user" << endl;
            else {
                add(inputs[1],inputs[2]);
            }
        }
        else if (inputs[0].compare("return") == 0) {

            if (counter != 3)
                cout << "incorrect input format" << endl;
            else if (!activeuser->isActive())
                cout << "not connected to a user" << endl;
            else {
                returnCommand(inputs[1],inputs[2]);
            }
        }
        else if (inputs[0].compare("status") == 0) {

            if (counter != 2)
                cout << "incorrect input format" << endl;
            else if (!activeuser->isActive())
                cout << "not connected to a user" << endl;
            else {
                status(inputs[1]);
            }
        }






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


    }

}

UserCommands::UserCommands(User *active) {
    this->activeuser=active;

}

void UserCommands::login(string version, string username, string password) {
    string strport=version.substr(0,':');

    string host = version.substr(':'+1);
    char char_array[strport.length() + 1];
    strcpy(char_array, strport.c_str());
    short port = atoi(char_array);
    ConnectionHandler* connectionHandler= new ConnectionHandler(host, port);
    if (!connectionHandler->connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
    }
    else{
        Connect ans("1.2",host,username,password);
        activeuser->setuserandpass(username,password);
        StompConnectionProtocal* stomp =new StompConnectionProtocal(activeuser,connectionHandler);
         std::thread th2(&StompConnectionProtocal::run,stomp);
       // StompConnectionProtocal stomp (activeuser,connectionHandler);
      //  std::thread th2(&StompConnectionProtocal::run,stomp);
    }

}

void UserCommands::subsribe(string topic) {
    int recite=activeuser->numForRecite();
    int id=activeuser->numForRecite();
    Subscribe ans(topic,id,recite);
    activeuser->addPendingrecite(recite,&ans);
}


void UserCommands::logout() {
    int recite = activeuser->numForRecite();
    Disconnect byebye=(recite);
    activeuser->addPendingrecite(recite, &byebye);
}

void UserCommands::status(string topic) {
    Send(topic,"book status");


}

void UserCommands::unsubsribe(string topic) {
    int id=activeuser->getidViaTopic(topic);
    Unsubscribe ans(id);
    //activeuser->unsubsribe(id,topic);


}

void UserCommands::add(string topic,string book) {
    Send ans(topic,(activeuser->getUsername()+" has added the book "+book));
    activeuser->addBook(topic,book);


}

void UserCommands::borrow(string topic,string book) {
        Send ans(topic,activeuser->getUsername()+" wish to borrow "+book);
        //activeuser->lookForBookToBorrow(topic,book);

}

void UserCommands::returnCommand(string topic,string book) {
    Send ans(topic,"Returning "+book+" to "+activeuser->returnBorrowedbook(topic,book));

}


