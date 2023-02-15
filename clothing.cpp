#include "clothing.h"
#include <ostream>
//#include <stream>
#include <iostream>
using namespace std;

Clothing::Clothing(const std::string category, const std::string name, int qty, double price, const std::string size, const std::string brand)
  :Product(category, name, price, qty),
  size_(size),
  brand_(brand)
{

}

set<string> Clothing::keywords() const{
  //set<string> keyWordsSet = setUnion(parseStringToWords(brand_), parseStringToWords(name));
  //keyWordsString += brand_ + " " + name;
  string keyWordsString = brand_ + " " + name_;
  set<string> keyWordsSet = parseStringToWords(keyWordsString);
  //keyWordsSet.insert(parseStringToWords(keyWordsString));
  return keyWordsSet;
}

string Clothing::displayString() const{
  //cout << Product::getName() << endl;
  //cout << "Size: " << size_ << "Brand: " << brand_ << endl;
  //cout << Product::getPrice() << Product::getQty() << "left" << endl;
  string display = Product::getName();
  double temp = getPrice();
  stringstream stream;
  stream << fixed << setprecision(2) << temp;
  string priceString = stream.str();
  display += "\nSize: " + size_ + " Brand: " + brand_ + "\n" + priceString + " " + to_string(getQty()) + " left.";
  return display;
}

void Clothing::dump(std::ostream& os) const
{
  Product::dump(os);
  os << size_ << "\n" << brand_ << "\n";
}