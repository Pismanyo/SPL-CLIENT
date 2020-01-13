//
// Created by liordu@wincs.cs.bgu.ac.il on 13/01/2020.
//

#ifndef BOOST_ECHO_CLIENT_BOOKS_H
#define BOOST_ECHO_CLIENT_BOOKS_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Book.h"

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::endl;
using std::map;

class Books {
private:
    map<string,Book> books;
    map<string,Book> booksBorrowed;
    map<string,Book> booksRentedOut;
    map<string,Book> booksWantingToborrow;
public:
    Books();
    bool hasBook(string book);
    bool hasbooksWantingToborrow(string book);
    bool hasBookBorrowed(string book);
    void addBook(Book book);
    void addbooksBorrowed (Book book);
    void addbooksWantingToborrow (Book book);
    void addBooksRentedOut(Book book);
    void removeBook(string name);
    void removeBookBorrwed(string book);
    void removeRentedOut(string name);
    void removebooksWantingToborrow(string name);
    Book getBook(string);
    Book getBookBorrwed(string);
    Book getBookRented(string);
    string allBooksOwned();


};


#endif //BOOST_ECHO_CLIENT_BOOKS_H
