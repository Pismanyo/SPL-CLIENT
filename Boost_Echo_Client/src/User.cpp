//
// Created by lior on 11/01/2020.
//

#include "User.h"

string User::getUsername() {
    return (*this->username);
}

string User::getPassword() {
    return (*this->password);
}

User::User(string* username, string* password) {
    this->username=username;
    active= false;
    this->password=password;


}

bool User::isActive() {
    return active;
}

void User::setActive(bool act) {
    this->active=act;


}

bool User::containsbook(string topic, string book) {
    for (string a :this->books[topic])
        if (a == book)
            return true;
    return false;
}

User::User() {
    this->active= false;
    awaiting= false;
}

void User::setuserandpass(string username, string passsword) {
    this->username=&username;
    this->password=&passsword;
    awaiting= true;
    this->reciteconter=0;

}

void User::setawait(bool await) {
    awaiting=await;

}

bool User::getawait() {
    return awaiting;
}

int User::numForRecite() {
    this->reciteconter++;
    return this->reciteconter;
}

bool User::isSubsribed(string topic) {
    if (TopicToId.count(topic) > 0)
    {
       return true;
    }
    return false;
}

//void User::adddfunction(int reicte, std::function <void()>fun) {
  //  this->idrecite.insert(std::pair<int,std::function<void()>(reicte,boost::lambda::bind(fun));

//}

void User::subsribe(string topic,int id) {
    this->TopicToId.insert({topic,id});
    this->IdToTopic.insert({id,topic});
    books.insert({topic,vector<string>()});
    lookingForBorrowedBooks.insert({topic,vector<string>()});
}

void User::addPendingrecite(int recite, Frame frame) {
    pendingrecite.insert({recite,frame});
}

int User::getidViaTopic(string topic) {
    return this->TopicToId[topic];

}

void User::unsubsribe(int id, string topic) {
    this->TopicToId.erase(topic);
    this->IdToTopic.erase(id);
    books.erase(topic);
    lookingForBorrowedBooks.erase(topic);

}

void User::addBook(string topic, string book) {
    this->books[topic].push_back(book);


}

void User::lookForBookToBorrow(string topic, string book) {
    this->lookingForBorrowedBooks[topic].push_back(book);
}

bool User::hasBorrowedbook(string topic, string book) {
    if(this->borrowedbooks[topic].count(book)>0)
        return true;
    return false;
}

string User::returnBorrowedbook(string topic, string book) {
    string ans=borrowedbooks[topic][book];
    borrowedbooks[topic].erase(book);
    return ans;
}

Frame User::getRecitebyId(int reciteid) {
    return this->pendingrecite[reciteid];
}




