#ifndef BOOK_H
#define BOOK_H
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <algorithm>
#include "product.h"
#include "util.h"
#include <set>

class Book : public Product{
public:
  Book(const std::string category, const std::string name, int qty, double price, const std::string ISBN, const std::string author);
  std::set<std::string> keywords() const ;
  bool isMatch(std::vector<std::string>& searchTerms) const;
  std::string displayString()const ;
  void dump(std::ostream& os) const ;

protected:
  std::string ISBN_;
  std::string author_;
};
#endif

