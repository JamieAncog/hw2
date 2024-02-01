#include <sstream>
#include <iomanip>
#include "product.h"
#include "book.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author) :
    Product(category, name, price, qty)
{
    isbn_ = isbn;
    author_ = author;
}

Book::~Book() {}

std::set<std::string> Book::keywords() const{
    std::set<std::string> mySet;
    return mySet;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const{
    bool myBool = true;
    return myBool;
}

std::string Book::displayString() const{
    std::string mySet;
    return mySet;
}

void Book::dump(std::ostream& os) const{

}
