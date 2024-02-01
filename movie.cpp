#include <sstream>
#include <iomanip>
#include "product.h"
#include "movie.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) :
    Product(category, name, price, qty)
{
    genre_ = genre;
    rating_ = rating;
}

Movie::~Movie() {}

std::set<std::string> Movie::keywords() const{
    std::set<std::string> mySet;
    return mySet;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const{
    bool myBool = true;
    return myBool;
}

std::string Movie::displayString() const{
    std::string mySet;
    return mySet;
}

void Movie::dump(std::ostream& os) const{

}