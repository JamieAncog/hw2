#include <sstream>
#include <iomanip>
#include "product.h"
#include "clothing.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) :
    Product(category, name, price, qty)
{
    size_ = size;
    brand_ = brand;
}

Clothing::~Clothing() {}

std::set<std::string> Clothing::keywords() const{
    std::set<std::string> mySet;
    return mySet;
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const{
    bool myBool = true;
    return myBool;
}

std::string Clothing::displayString() const{
    std::string mySet;
    return mySet;
}

void Clothing::dump(std::ostream& os) const{

}