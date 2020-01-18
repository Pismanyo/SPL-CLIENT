//
// Created by lior on 11/01/2020.
//

#ifndef CLIENT_USER_H
#define CLIENT_USER_H
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <boost/function.hpp>
#include <boost/lambda/bind.hpp>
#include "Frame.h"
#include "connectionHandler.h"
#include "Books.h"

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::endl;
using std::map;


class User {
private:
    string username;
    string password;
    map<string,Books> books;
    map<int,string> pendingrecite;
    bool active;
    bool terminate;
    bool awaiting;
    map<int,string> IdToTopic;
    map<string,int> TopicToId;
    int reciteconter;

public:
   // void adddfunction(int reicte,std::function <void()>a);
    User(string username,string password);
    User();
    bool isSubsribed(string topic);
    void addPendingrecite(int recite,string frame);
    int getidViaTopic(string topic);
    void subsribe(string topic,int id);
    string unsubsribe(int id);
    int numForRecite();
    string getUsername();
    bool getTerminate();
    void setTerminate(bool ans);
    string getPassword();
    bool isActive();
    void setActive(bool act);
    bool addBook(string topic, string book);
    bool containsbook(string topic, string book);
    void setuserandpass(string username,string passsword);
    void setawait(bool await);
    bool getawait();
    void addbooksWantingToborrow(string topic, string book);
    void rentBook(string topic,string book);
    void rentBorrowedBook(string topic,string book);
    bool hasbooksWantingToborrow(string topic, string book);
    bool hasBorrowedbook(string topic,string book);
    void addBorrowedbook(string topic,string book, string username);
    string returnBorrowedbook(string topic,string book);
    string getRecitebyId(int reciteid);
    void removeBookRentedOut(string topic,string book);
    string printBooksInTopic(string topic);

    bool addBooksNotSubsribed(string topic, string book);
};



#endif //CLIENT_USER_H
