
#include "User.h"

string User::getUsername() {return this->username;}

bool User::isActive() {return active;}

void User::setActive(bool act) {this->active=act;}

bool User::containsbook(string topic, string book) {return books[topic].hasBook(book);}

/**
 * User empty constructor.
 */
User::User():terminate(false) {
    this->active = false;
    awaiting = false;
}

/**
 * User constructor with username and password.
 * @param username User username.
 * @param passsword User password.
 */
void User::setuserandpass(string username, string passsword) {
    this->username=username;
    this->password=passsword;
    awaiting= true;
    this->reciteconter=0;
}

void User::setawait(bool await) {awaiting=await;}

/**
 * Increments and gives a receipt number.
 * @return A receipt number.
 */
int User::numForRecite() {
    this->reciteconter++;
    return this->reciteconter;
}

/**
 * Returns if a user is subscribed to the topic.
 * @param topic A topic.
 * @return True if the user is subscribed to the topic and false otherwise.
 */
bool User::isSubsribed(string topic) {
    if (TopicToId.count(topic) > 0)
       return true;
    return false;
}

/**
 * Subscribes the user to a topic with the given id.
 * @param topic A topic to subscribe to.
 * @param id The users subscription id at the topic.
 */
void User::subsribe(string topic,int id) {
    this->TopicToId.insert({topic,id});
    this->IdToTopic.insert({id,topic});
    if( this->books.count(topic)>0)
        this->books[topic].setsubbed(true);
     else
        this->books.insert({topic, Books()});
}

/**
 * Adds a book to the users book list while not being subscribed to that topic.
 * @param topic The books topic.
 * @param book The name of the book.
 * @return True if adding the book was successful and false otherwise.
 */
bool User::addBooksNotSubsribed(string topic,string book) {
    if(this->books.count(topic)==0) {
        this->books.insert({topic, Books()});
        this->books[topic].setsubbed(false);
    }
    if(! this->books[topic].hasBook(book)) {
        this->books[topic].addBook(Book(book));
        return true;
    }
    return false;
}

int User::getidViaTopic(string topic) {return this->TopicToId[topic];}

/**
 * Unsubscribes a user from a topic by subscription id.
 * @param id A users subscription id at a certain topic.
 * @return The topic matching the id given.
 */
string User::unsubsribe(int id) {
    string topic=this->IdToTopic[id];
    this->TopicToId.erase(topic);
    this->IdToTopic.erase(id);
    books.erase(topic);
    return topic;
}

/**
 * Adds a book to the users book list under the given topic.
 * @param topic A books topic.
 * @param book The name of the book.
 * @return True if the book was added and false otherwise.
 */
bool User::addBook(string topic, string book) {
    if(!this->containsbook(topic,book)) {
        this->books[topic].addBook(Book(book));
        return true;
    }
    return false;
}

/**
 * Checks if a user has a borrowed book.
 * @param topic The topic of the book.
 * @param book The name of the book.
 * @return True if the user has it and false otherwise.
 */
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

string User::getRecitebyId(int reciteid) {
    return this->pendingrecite[reciteid];
}

/**
 * Add a receipt we expect to receive an answer on from the server.
 * @param recite A receipt number.
 * @param frame A frame of the receipt.
 */
void User::addPendingrecite(int recite, string frame) {
    if(pendingrecite.count(recite)>0)
        pendingrecite.erase(recite);
    pendingrecite.insert({recite,frame});
}

/**
 * Adds a book to the borrowed books.
 * @param topic The topic of the book.
 * @param book The book name.
 * @param username The username the book belongs to.
 */
void User::addBorrowedbook(string topic, string book,string username) {
    this->books[topic].addbooksBorrowed(Book(book,username));
}

/**
 * Checks if the user has the book wanted to be borrowed by another user..
 * @param topic The topic of the book.
 * @param book The name of the book.
 * @return True if he has the book and false otherwise.
 */
bool User::hasbooksWantingToborrow(string topic, string book) {
    if(this->books[topic].hasbooksWantingToborrow(book))
    {
        this->books[topic].removebooksWantingToborrow(book);
        return true;
    }
    return false;
}

/**
 * Adds the books the user wants to borrow.
 * @param topic The topic of the book.
 * @param book The name of the book.
 */
void User::addbooksWantingToborrow(string topic, string book) {
    this->books[topic].addbooksWantingToborrow(Book(book));
}

/**
 * Rents the book to another user.
 * @param topic The topic of the book.
 * @param book The book name.
 */
void User::rentBook(string topic,string book) {
    Book a=this->books[topic].getBook(book);
    this->books[topic].addBooksRentedOut(a);
    this->books[topic].removeBook(book);
}

/**
 * Rents a book that was borrowed by the current user in first place.
 * @param topic The topic of the book.
 * @param book The book name.
 */
void User::rentBorrowedBook(string topic, string book) {
    Book a=this->books[topic].getBookBorrwed(book);
    this->books[topic].addBooksRentedOut(a);
    this->books[topic].removeBookBorrwed(book);
}

/**
 * Remove book from the rented out.
 * @param topic The topic of the book.
 * @param book The book name.
 */
void User::removeBookRentedOut(string topic, string book) {
    Book a=this->books[topic].getBookRented(book);
    if(a.isBorrowed())
        this->books[topic].addbooksBorrowed(Book(a.getName(), a.getUserBorrowedFrom()));
    else
        this->books[topic].addBook(Book(a.getName()));
    this->books[topic].removeRentedOut(book);
}

/**
 * Prints users books in the given topic.
 * @param topic A topic to print the books the user has in it.
 * @return The books the user has in the current topic.
 */
string User::printBooksInTopic(string topic) {
    return this->books[topic].allBooksOwned();
}

bool User::getTerminate() {return this->terminate;}

void User::setTerminate(bool ans) {this->terminate= ans;}






