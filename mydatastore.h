#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "datastore.h"
#include "util.h"
#include <queue>
#include <map>

class MyDataStore : public DataStore {
    public:
        MyDataStore();
        ~MyDataStore();

        /**
        * Adds a product to the data store
        */
        void addProduct(Product* p);

        /**
         * Adds a user to the data store
         */
        void addUser(User* u);

        User* isUserValid(std::string n) const;

        /**
         * Performs a search of products whose keywords match the given "terms"
         *  type 0 = AND search (intersection of results for each term) while
         *  type 1 = OR search (union of results for each term)
         */
        std::vector<Product*> search(std::vector<std::string>& terms, int type);

        /**
         * Reproduce the database file from the current Products and User values
         */
        void dump(std::ostream& ofile);

        void addCart(User* un, Product* prod);

        vector<Product*> viewCart(User* un);

    private:
        std::vector<User*> users_;
        std::map<User*, queue<Product*>> cart_;
        std::vector<Product*> products_;
};