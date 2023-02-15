#include "book.h"
#include <ostream>
#include <iostream>

using namespace std;
//the words in the author’s name should be searchable
//keywords as well as the book’s ISBN number

//book is derived from product.cpp
//needs name, price, quantity, ISBN, author

Book::Book(const std::string category, const std::string name, int qty, double price, const std::string ISBN, const std::string author)
  :Product(category, name, price, qty),
  ISBN_(ISBN),
  author_(author)
{

}

set<string> Book::keywords() const{
  set<string> author1 = parseStringToWords(author_);
  set<string> name1 = parseStringToWords(name_);
  set<string> keyWordsSet = setUnion(author1, name1);
  keyWordsSet.insert(ISBN_);
  return keyWordsSet;
}

string Book::displayString() const{
  //cout << Product::getName() << endl;
  //cout << "Author: " << author_ << "ISBN: " << ISBN_ << endl;
  //cout << Product::getPrice() << Product::getQty() << "left" << endl;
  //cout << "Here!" << endl;
  string display = Product::getName();
  double temp = getPrice();
  stringstream stream;
  stream << fixed << setprecision(2) << temp;
  string priceString = stream.str();
  display += "\nAuthor: " + author_ + " ISBN: " + ISBN_ + "\n" + priceString + " " + to_string(getQty()) + " left.";
  return display;
}
bool Book::isMatch(std::vector<std::string>& searchTerms) const{
  // vector<std::string>::iterator iter = searchTerms.begin();
  // for (iter; iter < searchTerms.end(); iter++){
  //   if (iter == ){
  //     return true;
  //   }
  // }
  return false;

}
void Book::dump(std::ostream& os) const
{
  Product::dump(os);
  os << ISBN_ << "\n" << author_ << "\n";
}