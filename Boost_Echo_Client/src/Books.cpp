//
// Created by liordu@wincs.cs.bgu.ac.il on 13/01/2020.
//

#include "Books.h"

Books::Books() {
}

bool Books::hasBook(string book) {
    if(this->books.count(book)>0)
        return true;
    return false;
}

bool Books::hasBookBorrowed(string book) {
    if(this->booksBorrowed.count(book)>0)
        return true;
    return false;
}

void Books::addBook(Book book) {
    this->books.insert({book.getName(),book});
}

void Books::addbooksBorrowed(Book book) {
    this->booksBorrowed.insert({book.getName(),book});
}

void Books::addBooksRentedOut(Book book) {
    this->booksRentedOut.insert({book.getName(),book});

}

void Books::removeBook(string name) {
    this->books.erase(name);
}

void Books::removeBookBorrwed(string book) {
    this->booksBorrowed.erase(book);
}

void Books::removeRentedOut(string name) {
    this->booksRentedOut.erase(name);
}

Book Books::getBook(string name) {
    return this->books[name];
}

Book Books::getBookBorrwed(string name) {
    return this->booksBorrowed[name];
}

Book Books::getBookRented(string name) {
    return this->booksRentedOut[name];
}

bool Books::hasbooksWantingToborrow(string book) {
    if(this->booksWantingToborrow.count(book)>0)
        return true;
    return false;
}

void Books::addbooksWantingToborrow(Book book) {
    this->booksWantingToborrow.insert({book.getName(),book});
}

void Books::removebooksWantingToborrow(string book) {
    this->booksBorrowed.erase(book);
}

string Books::allBooksOwned() {
    string ans="";
    for(auto it = books.begin(); it != books.end(); ++it)
    {
        ans+=it->first+",";
    }
    for(auto it = booksBorrowed.begin(); it != booksBorrowed.end(); ++it)
    {
        ans+=it->first+",";
    }
    ans=ans.substr(0,ans.length()-1);
    return ans;
}
