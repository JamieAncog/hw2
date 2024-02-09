#include "mydatastore.h"

using namespace std;

MyDataStore::MyDataStore(){

}

MyDataStore::~MyDataStore(){
    for (int i = (int) users_.size()-1; i >= 0; i--){
        delete users_[i];
    }
    for (int i = (int) products_.size()-1; i >= 0; i--){
        delete products_[i];
    }
}

/**
 * Adds a product to the data store
 */
void MyDataStore::addProduct(Product* p){
    products_.push_back(p);
}

/**
 * Adds a user to the data store
 */
void MyDataStore::addUser(User* u){
    users_.push_back(u);
    queue<Product*> mq;
    cart_.insert(std::pair<User*, queue<Product*>>(u, mq));
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    std::vector<Product*> myProds;
    std::set<string> mySet;
    for (int i = 0; i < (int) terms.size(); i++){
        mySet.insert(terms[i]);
    }
    if (type == 0){
        for (int i = 0; i < (int) products_.size(); i++){
            std::set<string> keys = products_[i]->keywords();
            std::set<string> myInterS = setIntersection<string>(keys, mySet);  
            if (myInterS.size() >= terms.size()){
                myProds.push_back(products_[i]);
            }
        }
    }
    else {
        for (int i = 0; i < (int) products_.size(); i++){
            std::set<string> keys = products_[i]->keywords();
            std::set<string> myUnion = setUnion<string>(keys, mySet);
            if (myUnion.size() < keys.size() + mySet.size()){
                myProds.push_back(products_[i]);
            }
        }
    }
    return myProds;
}

/**
 * Reproduce the database file from the current Products and User values
 */
void MyDataStore::dump(std::ostream& ofile){
    ofile << "<products>" << endl;

    for (int i = 0; i < (int) products_.size(); i++){
        ofile << products_[i]->getCat() << endl;
        ofile << products_[i]->getName() << endl;
        ofile << products_[i]->getPrice() << endl;
        ofile << products_[i]->getQty() << endl;
        
        if (products_[i]->getCat() == "book"){
            Book* myBook = (Book*) products_[i];
            ofile << myBook->getIsbn() << endl;
            ofile << myBook->getAuthor() << endl;
        }
        else if (products_[i]->getCat() == "clothing"){
            Clothing* myClothing = (Clothing*) products_[i];
            ofile << myClothing->getSize() << endl;
            ofile << myClothing->getBrand() << endl;
        }
        else if (products_[i]->getCat() == "movie"){
            Movie* myMovie = (Movie*) products_[i];
            ofile << myMovie->getGenre() << endl;
            ofile << myMovie->getRating() << endl;
        }
    }

    ofile << "</products>" << endl;

    ofile << "<users>" << endl;

    for (int i = 0; i < (int) users_.size(); i++){
        users_[i]->dump(ofile);
    }

    ofile << "</users>" << endl;
}

User* MyDataStore::getCurrUser(std::string n) const{
    User* myUser = NULL;
    for (int i = 0; i < (int) users_.size(); i++){
        if (users_[i]->getName() == n){
            myUser = users_[i];
        }
    }
    return myUser;
}

void MyDataStore::addCart(User* un, Product* prod){
    cart_[un].push(prod);
}

void MyDataStore::viewCart(User* un){
    queue<Product*> myCart = cart_[un];
    int count = 1;
    while (!(myCart.empty())){
        cout << "Item " << count << endl;
        count++;
        cout << myCart.front()->displayString() << endl;
        cout << endl;
        myCart.pop();
    }
}

void MyDataStore::buyCart(User* un){
    queue<Product*> stillInCart;
    while (!(cart_[un].empty())){
        if (cart_[un].front()->getQty() > 0 && un->getBalance() > cart_[un].front()->getPrice()){
            cart_[un].front()->subtractQty(1);
            un->deductAmount(cart_[un].front()->getPrice());
        }
        else {
            stillInCart.push(cart_[un].front());
        }
        cart_[un].pop();
    }
    cart_[un] = stillInCart;
}
