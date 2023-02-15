#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{ //check for case insesitive words
    set<std::string> keyWords;
    string temp;
    for (unsigned int i = 0; i < rawWords.length(); i++){
      if (ispunct(rawWords[i]) || isspace(rawWords[i])){ //if i encounter a punctuation or space
        if (temp.length() >= 2){
          temp = convToLower(temp);
          keyWords.insert(temp);
        }
        temp.clear();
      }
      else {
        temp += rawWords[i];
      }
    }
    if(temp.length() >= 2) {
      temp = convToLower(temp);
      keyWords.insert(temp);
    }
    return keyWords;
/*
    stringstream ss(rawWords);
    string eachWord;
    //check for a-z
    //isalpha()
    while (ss >> eachWord) { //splits each word
        string temp;
        for (int i = 0; i < eachWord.length(); i++){
            if (ispunct(eachWord[i])){ //if there is punct in word
                if (eachWord.substr(0,i+1).length >= 2){
                    keyWords.insert(eachWord.substr(0,i+1));
                }
                else if (eachWord.substr(i).length >= 2){
                    keyWords.insert(eachWord.substr(i));
                }
            }
      keyWords.insert(eachWord); //add if no punct
      } 
    }*/
 //substr to get ech word
 //ispunct - to check which char is a punct

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
