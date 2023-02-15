#ifndef CLOTHING_H
#define CLOTHING_H
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <algorithm>
#include "product.h"
#include "util.h"
#include <set>


class Clothing: public Product{
public:
  Clothing(const std::string category, const std::string name, int qty, double price, const std::string size, const std::string brand);
  std::set<std::string> keywords() const override;
  //bool isMatch(std::vector<std::string>& searchTerms)
  std::string displayString() const override;
  void dump(std::ostream& os) const override;

protected:
  std::string size_;
  std::string brand_;
};
#endif

