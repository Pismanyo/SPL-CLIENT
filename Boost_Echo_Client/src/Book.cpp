//
// Created by liordu@wincs.cs.bgu.ac.il on 13/01/2020.
//

#include "Book.h"


Book::Book(string name) {
    this->name=name;
    borrowedFrom= false;
    this->borrowedFrom="";

}

Book::Book(string name, string username) {
    this->boorowed=true;
    this->name=name;
    this->borrowedFrom=username;
}

string Book::getName() {
    return this->name;
}

string Book::getUserBorrowedFrom() {
    return borrowedFrom;
}

bool Book::isBorrowed() {
    return boorowed;
}

Book::Book() {

}
