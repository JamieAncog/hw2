#include <sstream>
#include <iomanip>
#include "product.h"
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author) :
    Product(category, name, price, qty)
{
    isbn_ = isbn;
    author_ = author;
}

Book::~Book() {}

std::set<std::string> Book::keywords() const{
    std::set<std::string> keys;
    std::set<std::string> authorKeys = parseStringToWords(author_);
    std::set<std::string> nameKeys = parseStringToWords(name_);
    for (std::set<std::string>::iterator it = authorKeys.begin(); it != authorKeys.end(); ++it){
        keys.insert(*it);
    }
    for (std::set<std::string>::iterator it = nameKeys.begin(); it != nameKeys.end(); ++it){
        keys.insert(*it);
    }
    keys.insert(isbn_);
    return keys;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const{
    bool myBool = true;
    return myBool;
}

std::string Book::displayString() const{
    std::string myInfo;
    myInfo += "Name: " + name_ + ", ";
    stringstream ss;
    ss << price_;
    std::string temp;
    ss >> temp;
    myInfo += "Price: " + temp + ", ";
    myInfo += "Quantity: " + to_string(qty_) + ", ";
    myInfo += "ISBN: " + isbn_ + ", ";
    myInfo += "Author: " + author_;
    return myInfo;
}

void Book::dump(std::ostream& os) const{
    os << this->displayString() << endl;
}
