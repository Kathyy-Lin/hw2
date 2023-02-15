
#include "datastore.h"
#include "util.h"
#include "product.h"
#include "book.h"
#include "movie.h"
#include "clothing.h"
#include "user.h"
#include <map>

class MyDataStore: public DataStore{
public:
    MyDataStore();
    ~MyDataStore();
    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void addToCart(std::string username, Product* p);
    void viewCart(std::string username);
    void buyCart(std::string username);
    void dump(std::ostream& ofile);

private:
    std::map<std::string, std::set<Product*>> keywordMap;
    std::vector<Product*> allProducts_;
    std::map<std::string, User*> allUsers_;
    std::map<std::string, std::vector<Product*>> carts_;
};