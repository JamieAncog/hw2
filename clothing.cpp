#include <sstream>
#include <iomanip>
#include "product.h"
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand) :
    Product("Clothing", name, price, qty)
{
    size_ = size;
    brand_ = brand;
}

Clothing::~Clothing() {}

std::set<std::string> Clothing::keywords() const{
    std::set<std::string> keys;
    std::set<std::string> brandKeys = parseStringToWords(brand_);
    std::set<std::string> nameKeys = parseStringToWords(name_);
    for (std::set<std::string>::iterator it = brandKeys.begin(); it != brandKeys.end(); ++it){
        keys.insert(*it);
    }
    for (std::set<std::string>::iterator it = nameKeys.begin(); it != nameKeys.end(); ++it){
        keys.insert(*it);
    }
    return keys;
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const{
    bool myBool = true;
    return myBool;
}

std::string Clothing::displayString() const{
    std::string myInfo;
    myInfo += name_ + "\n";
    stringstream ss;
    ss << price_;
    std::string temp;
    ss >> temp;
    myInfo += "Size: " + size_;
    myInfo += " Brand: " + brand_ + "\n";
    myInfo += temp;
    myInfo += " " + to_string(qty_) + " left";
    return myInfo;
}

void Clothing::dump(std::ostream& os) const{
    os << this->displayString() << endl;
}

std::string Clothing::getSize() const{
    return size_;
}

std::string Clothing::getBrand() const{
    return brand_;
}
