
#include "connectionHandler.h"
#include "Frame.h"
#include "StompConnectionProtocal.h"
#include "UserCommands.h"

UserCommands::UserCommands(User* active,StompConnectionProtocal* stomp,Connect a) :activeuser(active),stomp(stomp)
, finalTerminate(false){
    this->stomp->send(a.toString());
}

/**
 * Splits a message.
 * @param tosplite A message to split.
 * @param delimiter A delimiter to split the message by.
 * @return A vector containing the split message.
 */
vector<string> UserCommands::split(string tosplite,char delimiter)
{
    stringstream split(tosplite);
    string token;
    vector<string> ans;
    while(getline(split,token,delimiter))
        ans.push_back(token);
    return ans;

}

/**
 * Handles keyboard input by the client.
 */
void UserCommands::run() {

    string answer1;
    int counter;
    bool toTerminate= false;
    while (!toTerminate) {
        getline(cin, answer1);
        vector<string> inputs = this->split(answer1, ' ');
        counter = inputs.size();
        if(counter>0) {
            if (inputs[0].compare("login") == 0) {
                if (activeuser->isActive())
                    cout << "Already connected to different user" << endl;
            } else if (inputs[0].compare("join") == 0) {
                if (counter != 2)
                    cout << "incorrect input format" << endl;
                else if (!activeuser->isActive())
                    cout << "not connected to a user" << endl;

                else {
                    subsribe(inputs[1]);
                }

            } else if (inputs[0].compare("exit") == 0) {

                if (counter != 2)
                    cout << "incorrect input format" << endl;
                else if (!activeuser->isActive())
                    cout << "not connected to a user" << endl;
                else {
                    unsubsribe(inputs[1]);
                }
            } else if (inputs[0].compare("borrow") == 0) {

                if (counter < 2)
                    cout << "incorrect input format" << endl;
                else if (!activeuser->isActive())
                    cout << "not connected to a user" << endl;

                else {
                    for (int i = 3; i < counter; i++)
                        inputs.at(2) += " " + inputs.at(i);
                    borrow(inputs[1], inputs[2]);
                }
            } else if (inputs[0].compare("logout") == 0) {

                if (counter != 1)
                    cout << "incorrect input format" << endl;
                else if (!activeuser->isActive())
                    cout << "not connected to a user" << endl;
                else {
                    logout();
                }

            } else if (inputs[0].compare("add") == 0) {

                if (counter < 3)
                    cout << "incorrect input format" << endl;
                else if (!activeuser->isActive())
                    cout << "not connected to a user" << endl;
                else {
                    for (int i = 3; i < counter; i++)
                        inputs.at(2) += " " + inputs.at(i);
                    add(inputs[1], inputs[2]);
                }
            } else if (inputs[0].compare("return") == 0) {

                if (counter < 3)
                    cout << "incorrect input format" << endl;
                else if (!activeuser->isActive())
                    cout << "not connected to a user" << endl;
                else {
                    for (int i = 3; i < counter; i++)
                        inputs.at(2) += " " + inputs.at(i);
                    returnCommand(inputs[1], inputs[2]);
                }
            } else if (inputs[0].compare("status") == 0) {

                if (counter != 2)
                    cout << "incorrect input format" << endl;
                else if (!activeuser->isActive())
                    cout << "not connected to a user" << endl;
                else {
                    status(inputs[1]);
                }
            }
        }
        toTerminate=activeuser->getTerminate();
    }
}

/**
 * Sends a frame to subscribe to a given topic.
 * @param topic A topic to subscribe to.
 */
void UserCommands::subsribe(string topic) {
    int recite=activeuser->numForRecite();
    int id=activeuser->numForRecite();
    Subscribe ans(topic,id,recite);
    activeuser->addPendingrecite(recite,ans.toString());
    this->stomp->send(ans.toString());
}

/**
 * Logs out from the user.
 */
void UserCommands::logout() {
    this->activeuser->setTerminate(true);
    int recite = activeuser->numForRecite();
    Disconnect byebye(recite);
    activeuser->addPendingrecite(recite, byebye.toString());
    this->stomp->send(byebye.toString());
}

/**
 * Shows the books the user has at a topic.
 * @param topic A topic to show the books the user has in it.
 */
void UserCommands::status(string topic) {
    Send ans(topic,"book status");
    this->stomp->send(ans.toString());


}

/**
 * Unsubscribes a user from a given topic.
 * @param topic A topic to unsubscribe from.
 */
void UserCommands::unsubsribe(string topic) {
    int id=activeuser->getidViaTopic(topic);
    Unsubscribe ans(id);
    this->activeuser->addPendingrecite(id,ans.toString());
    this->stomp->send(ans.toString());
}

/**
 * Adds a book to a topic.
 * @param topic A topic to add a book to.
 * @param book The books name.
 */
void UserCommands::add(string topic,string book) {
    if(!activeuser->isSubsribed(topic)) {
        if (!activeuser->addBooksNotSubsribed(topic, book))
            cout << "book already exists" << endl;
    }
    else {
        if(!activeuser->addBook(topic, book))
                cout << "book already exists" << endl;
        else {
            Send ans(topic, (activeuser->getUsername() + " has added the book " + book));
            this->stomp->send(ans.toString());
        }
    }
}

/**
 * Sends a frame to the server to borrow a book.
 * @param topic The topic of the book.
 * @param book  The book name.
 */
void UserCommands::borrow(string topic,string book) {
        Send ans(topic,activeuser->getUsername()+" wish to borrow "+book);
        this->stomp->send(ans.toString());
}

/**
 * A command to return the book from the user we borrowed it from.
 * @param topic The topic of the book.
 * @param book The book name.
 */
void UserCommands::returnCommand(string topic,string book) {
    Send ans(topic,"Returning "+book+" to "+activeuser->returnBorrowedbook(topic,book));
    this->stomp->send(ans.toString());
}



