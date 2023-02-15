//need to add headers
#include "mydatastore.h"
using namespace std;


MyDataStore::MyDataStore()
{
//nothing in here
}

MyDataStore::~MyDataStore()
{
  for (unsigned int i = 0; i < allProducts_.size(); i++){
    delete allProducts_[i];
  }
  map<string, User*>:: iterator temp1;
  for (temp1 = allUsers_.begin(); temp1 != allUsers_.end(); temp1++){
    delete (temp1)->second;
  }
}

void MyDataStore::addProduct(Product* p)
{
//use map, keywords 
//create a map
  //add all (Product* P) to allProducts_ in product parser add product
  allProducts_.push_back(p);
  //std::map<std::string, std::string> mapOfKeywords;
  //key are the keywords
  set<string> keywordKeys = p->keywords();
  std::set<std::string>::iterator it;
  for (it=keywordKeys.begin(); it != keywordKeys.end(); it++){
    if (keywordMap.find(*it) != keywordMap.end()){ //there exists a keyword already
       set<Product*> temp;
       keywordMap.insert(make_pair(*it, temp));
    }
    keywordMap[*it].insert(p);
  }

  //values are the items for that keyword

}

void MyDataStore::addUser(User* u)
{
//map of usernames to each indivodual cart 
  std::vector<Product*> cart;
  allUsers_.insert(make_pair(u->getName(),u));
  carts_.insert(make_pair(u->getName(),cart));
}

vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
  set<Product*>::iterator itr;
  vector<Product*> productVector;
  //get first term
  set<Product*> currentItem = keywordMap[terms[0]];
  for (unsigned int i = 1; i < terms.size(); i++){
    if (type == 0){ //Intersection
      currentItem = setIntersection(currentItem, keywordMap[terms[i]]);
    }
    else if (type == 1){ //Union
      currentItem = setUnion(currentItem, keywordMap[terms[i]]);
    }
    else{ //will exit whole function so doesn't go into next for loop
      cout << "Invalid request" << endl;
      //return empty vector
      vector<Product*> invalid;
      return invalid;
    }
  }
  for (itr = currentItem.begin(); itr != currentItem.end(); itr ++){
    productVector.push_back(*itr);
  }
  return productVector;
 //Results must be displayed to the user via the 
 //displayProducts(vector<Product*>& hits); function provided in amazon.cpp



  //set of items with first keyword
  //0 is intersection, 1 is union
  /*vector<string> currentItems = keywordMap.find(terms.begin())->second; 
  vector<string> temporaryItems = "";
  //how do i start with the second value in the set
  for (itr = terms.begin()->next; itr != terms.end(); itr++){
    //if keyword exists in the map
    if (keywordMap.find(itr)!= keywordMap.end()){
      temporaryItems.clear();
      temporaryItems = keywordMap.find(itr)->second;
      //check whether it is AND or OR
      if (input.substr(0,input.find(" ")) == "and"){
        //compare items of the temporarykeywords and current Items
        currentItems = setIntersection(currentItems, temporaryItems);
      }
      else if (input.substr(0,input.find(" ")) == "or"){
        currentItems = setUnion(currentItems, temporaryItems);
      }
    }
  }
  //convert currentitems set to vector
  vector <Products*> hits(currentItems.begin(), currentItems.end());
  //display the hits in amazon.cpp
  displayProducts(vector<Product*>& hits);*/
} 

void MyDataStore::addToCart(std::string username, Product* p)
{
//check if valid user, then add items to their cart
  if (allUsers_.find(username) == allUsers_.end()){ 
    cout << "Invalid request" << endl;
    return;
  }
  //do i have to check if it is a valid product
  else{
    //add items to their cart
    //map<string, vector<Product*>>::iterator it;
    //for (int i = ; it!=carts_.end(); ++it){
      //go into username's cart
      //cout <<"before"<< carts_[username].size();
      carts_[username].push_back(p);
      //cout << "after" << carts_[username].size();
  }
}

void MyDataStore::viewCart(std::string username)
{
//check for valid user
  if (allUsers_.find(username) == allUsers_.end()){ 
    cout << "Invalid Username" <<endl;
  }
  else{
    //display user, iterate through cart and dump each product
    //map<string, vector<Product*>>::iterator it;
    //for (it = carts_.begin(); it!=carts_.end(); it++){
      //cout << "here";
        vector<Product*> totalProducts = carts_[username];
        //vector<Product*>::iterator it1;
        //cout << totalProducts.size();
        for (unsigned int i = 0; i < totalProducts.size(); i++){
          cout << "Item " << i+1 << "\n" <<totalProducts[i]->displayString() << endl;
        }
      }
  
    /*
    std::vector<Product*>cart = carts_.find(username)->second;
    for (int i = 0; i < cart.size(); i++){
      std::cout << "Item #" << i <<endl;
      cart[i]->displayString();
    }*/
  
  //std::cout << "" << std::endl;
}
//FIND USER, given a user, it returns a pointer to a user

void MyDataStore::buyCart(std::string username)
{
//checkusername, if not valid return invalid username
  if (allUsers_.find(username) == allUsers_.end()){ 
    cout << "Invalid Username" << endl;
    return;
  }
  else{
    //go though the cart of username
    map<string, User*>::iterator userIT = allUsers_.find(username);

    map<string, vector<Product*>>::iterator it;
    vector<Product*> tempUserNotBought;
    it = carts_.find(username);
      if (it != carts_.end()){
        vector<Product*>::iterator it1;
        for (it1 = (it->second).begin(); it1!= (it->second).end(); it1++){
          //if (each item in the cart has enough quantity and the user has enough balance
          if (((*it1)->getQty() > 0) && (userIT->second->getBalance() >= (*it1)->getPrice())){
            (*it1)->subtractQty(1);
            userIT->second->deductAmount((*it1)->getPrice());
          }
          else{//not able to buy item
            tempUserNotBought.push_back(*it1);
          }
        }
      }
    carts_[username] = tempUserNotBought; //set to current cart
  }
}

/*User* currentUser = allUsers_.find(username);
    std::vector<Product*>cart = carts_.find(username)->second;
    for (int i = 0; i < cart.size(); i++){
      //if there is enough quantity and the user has enough balance
      if ((cart[i]->getQty() > 0) && (currentUser->getBalance() >= cart[i]->getPrice())){
        //decrease stock by one
        cart[i]->subtractQty(1);
        //decrease user balance
        currentUser->deductAmount(cart[i]->getPrice());
      }
    }
    */
/*
void MyDataStore::checkusername()
{
  //check if username exists
}*/

void MyDataStore::dump(std::ostream& os)
{
//follow output parameter exactly
//use "os<<" to output into output file
//then iterate through all products + users invoking their indivudual dump functions
  //os << genre_ << "\n" << rating_ << "\n" << endl;
  os << "<products>" << endl;
  cout << allProducts_.size() <<endl;
  for (unsigned int i = 0; i < allProducts_.size(); i++){
    allProducts_[i]->dump(os);
  }
  os << "</products>" << endl;
  os << "<users>" << endl;
  map<string, User*>::const_iterator userITR;
  for (userITR=allUsers_.begin(); userITR != allUsers_.end(); userITR++){
    userITR -> second ->dump(os);
  }
  os << "</users>" << endl;
}