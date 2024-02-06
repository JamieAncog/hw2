#include "mydatastore.h"

using namespace std;

MyDataStore::MyDataStore(){

}

MyDataStore::~MyDataStore(){

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
    cout << "<products>" << endl;

    for (int i = 0; i < (int) products_.size(); i++){
        cout << products_[i]->getName() << endl;
        cout << products_[i]->getPrice() << endl;
        cout << products_[i]->getQty() << endl;
        
        if (products_[i]->getCat() == "book"){
            Book* myBook = (Book*) products_[i];
            cout << myBook->getIsbn() << endl;
            cout << myBook->getAuthor() << endl;
        }
        else if (products_[i]->getCat() == "clothing"){
            Clothing* myClothing = (Clothing*) products_[i];
            cout << myClothing->getSize() << endl;
            cout << myClothing->getBrand() << endl;
        }
        else if (products_[i]->getCat() == "movie"){
            Movie* myMovie = (Movie*) products_[i];
            cout << myMovie->getGenre() << endl;
            cout << myMovie->getRating() << endl;
        }
    }

    cout << "</products>" << endl;

    for (int i = 0; i < (int) users_.size(); i++){
        users_[i]->dump(cout);
    }

    cout << "<users>" << endl;



    cout << "</users>" << endl;
}
