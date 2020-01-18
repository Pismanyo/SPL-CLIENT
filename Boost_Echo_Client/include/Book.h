
#ifndef BOOST_ECHO_CLIENT_BOOK_H
#define BOOST_ECHO_CLIENT_BOOK_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::endl;
using std::map;

class Book {
private:
    string name;
    string borrowedFrom{};
    bool boorowed;
public:
    Book();
    Book(string name);
    Book(string name,string username);
    string getName();
    string getUserBorrowedFrom();
    bool isBorrowed();
};

#endif
