
#include "Book.h"

Book::Book() : name(""), boorowed(false) {}

Book::Book(string name): name(name), boorowed(false){this->borrowedFrom = "";}

Book::Book(string name, string username) : name(name), boorowed(true){this->borrowedFrom=username;}

string Book::getName() {return this->name;}

string Book::getUserBorrowedFrom() {return borrowedFrom;}

bool Book::isBorrowed() {return boorowed;}


