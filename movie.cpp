#include "movie.h"
using namespace std;

Movie::Movie(const std::string category, const std::string name, int qty, double price, const std::string genre, const std::string rating)
  :Product(category, name, price, qty),
  genre_(genre),
  rating_(rating)
{

}

set<string> Movie::keywords() const{
  set<string> keywordGenre = parseStringToWords(genre_);
  set<string> keywordName = parseStringToWords(name_);
  set<string> keyWordsSet = setUnion(keywordGenre, keywordName);
  // keyWordsSet.insert(rating_);
  return keyWordsSet;
}

string Movie::displayString() const{
  //cout << Product::getName() << endl;
  //cout << "Genre: " << genre_ << "Rating: " << rating_ << endl;
  //cout << Product::getPrice() << Product::getQty() << "left" << endl;
  string display = Product::getName();
  double temp = getPrice();
  stringstream stream;
  stream << fixed << setprecision(2) << temp;
  string priceString = stream.str();
  display += "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + priceString + " " + to_string(getQty()) + " left.";
  return display;
}
bool Movie::isMatch(std::vector<std::string>& searchTerms) const{
  return false;
}

void Movie::dump(std::ostream& os) const
{
  Product::dump(os);
  os << genre_ << "\n" << rating_ << "\n";
}