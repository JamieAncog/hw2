#include <sstream>
#include <iomanip>
#include "product.h"
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating) :
    Product("Movie", name, price, qty)
{
    genre_ = genre;
    rating_ = rating;
}

Movie::~Movie() {}

std::set<std::string> Movie::keywords() const{
    std::set<std::string> keys;
    std::set<std::string> genreKeys = parseStringToWords(genre_);
    std::set<std::string> nameKeys = parseStringToWords(name_);
    for (std::set<std::string>::iterator it = genreKeys.begin(); it != genreKeys.end(); ++it){
        keys.insert(*it);
    }
    for (std::set<std::string>::iterator it = nameKeys.begin(); it != nameKeys.end(); ++it){
        keys.insert(*it);
    }
    return keys;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const{
    bool myBool = true;
    return myBool;
}

std::string Movie::displayString() const{
    std::string myInfo;
    myInfo += name_ + "\n";
    stringstream ss;
    ss << price_;
    std::string temp;
    ss >> temp;
    myInfo += "Genre: " + genre_;
    myInfo += " Rating: " + rating_ + "\n";
    myInfo += temp;
    myInfo += " " + to_string(qty_) + " left";
    return myInfo;
}

void Movie::dump(std::ostream& os) const{
    os << this->displayString() << endl;
}