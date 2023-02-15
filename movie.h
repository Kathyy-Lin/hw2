#ifndef MOVIE_H
#define MOVIE_H

#include <sstream>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <algorithm>
#include "product.h"
#include "util.h"
#include <set>

class Movie: public Product{
public:
  Movie(const std::string category, const std::string name, int qty, double price, const std::string genre, const std::string rating);
  std::set<std::string> keywords() const override;
  bool isMatch(std::vector<std::string>& searchTerms) const;
  std::string displayString() const override;
  void dump(std::ostream& os) const override;

protected:
  std::string genre_;
  std::string rating_;
};
#endif