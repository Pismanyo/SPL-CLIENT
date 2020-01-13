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
    return books[topic].hasBook(book);
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
    this->books.insert({topic,Books()});
    //books.insert({topic,vector<string>()});
   // lookingForBorrowedBooks.insert({topic,vector<string>()});
  //  borrowedbooks.insert({topic,map<string,string>()});
}

int User::getidViaTopic(string topic) {
    return this->TopicToId[topic];

}

void User::unsubsribe(int id) {
    string topic=this->IdToTopic[id];
    this->TopicToId.erase(topic);
    this->IdToTopic.erase(id);
    books.erase(topic);
    //lookingForBorrowedBooks.erase(topic);
   // borrowedbooks.erase(topic);

}

void User::addBook(string topic, string book) {
    this->books[topic].addBook(Book(book));


}
bool User::hasBorrowedbook(string topic, string book) {
    if(this->books[topic].hasBookBorrowed(book))
        return true;
    return false;
}

string User::returnBorrowedbook(string topic, string book) {

    string ans=this->books[topic].getBookBorrwed(book).getUserBorrowedFrom();
    this->books[topic].removeBookBorrwed(book);
    return ans;
}

Frame* User::getRecitebyId(int reciteid) {
    return this->pendingrecite[reciteid];
}

void User::addPendingrecite(int recite, Frame *frame) {
    pendingrecite.insert({recite,frame});
}


void User::addBorrowedbook(string topic, string book,string username) {
    this->books[topic].addbooksBorrowed(Book(book,username));
    //this->borrowedbooks[topic].insert({book,username});

}

bool User::hasbooksWantingToborrow(string topic, string book) {
    if(this->books[topic].hasbooksWantingToborrow(book))
    {
        this->books[topic].removebooksWantingToborrow(book);
        return true;
    }
    return false;
}

void User::addbooksWantingToborrow(string topic, string book) {
    this->books[topic].addbooksWantingToborrow(Book(book));
}

void User::rentBook(string topic,string book) {
    Book a=this->books[topic].getBook(book);
    this->books[topic].addBooksRentedOut(Book(a.getName()));
    this->books[topic].removeBook(book);



}

void User::rentBorrowedBook(string topic, string book) {
    Book a=this->books[topic].getBookBorrwed(book);
    this->books[topic].addBooksRentedOut(Book(a.getName(),a.getUserBorrowedFrom()));
    this->books[topic].removeBookBorrwed(book);

}

void User::removeBookRentedOut(string topic, string book) {
    Book a=this->books[topic].getBookRented(book);
    if(a.isBorrowed()) {
        this->books[topic].addbooksBorrowed(Book(a.getName(), a.getUserBorrowedFrom()));
    }
    else {
        this->books[topic].addBook(Book(a.getName()));
    }

}

string User::printBooksInTopic(string topic) {
    return this->books[topic].allBooksOwned();
}






