#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> fields;
string requirements[7] = {"byr","iyr","eyr","hgt","hcl","ecl","pid"};

void reset_map() {

  for (int i = 0; i < 7; i+b)
    { fields[requirements[i]] = false; }

void papers_please(field, content) {
  int size;

  if (field == "byr" && stoi(content) > 1920 && stoi(content) < 2003)
    { fields[field] = true; }

  else if (field == "iyr" && stoi(content) > 2010 && stoi(content) < 2020)
    { fields[field] = true; }

  else if (field == "eyr" && stoi(content) > 2020 && stoi(content) < 2030)
    { fields[field] = true; }

  else if (field == "hgt")
    {
      if (content.find("cm") != string::npos)
        { size = stoi(content.substr(0, content.find("cm")-1));
          if (size > 149 && size < 193)
            { fields[field] = true; }
        }

      if (content.find("in") != string::npos)
        { size = stoi(content.substr(0, content.find("cm")-1));
          if (size > 59 && size < 76)
            { fields[field] = true; }
        }
    }




      fields[field] = true; }

bool is_valid() {
  bool valid = true;

  for (int i =0; i < 7; i++) {
    if (!fields[requirements[i]])
      { valid = false; }
  }
  return valid;
}


void string_parser(string passport) {
  int token_indx;
  int colon_indx;
  string content;
  string field;

  token_indx = passport.find(' ');
  colon_indx = passport.find(':');
  field = passport.substr(0,3);
  content = passport.substr(colon_indx + 1, token_indx - colon_indx -1);

  fields[field] = true;

  if (token_indx != string::npos ) {

    passport = passport.substr(token_indx +1 , passport.length() - token_indx -1);

    if (passport.length() > 2)
      { string_parser(passport); }
  }
}

int main() {
  ifstream file("test_input.txt");
  string str;
  int valid_ones = 0;

  reset_map();

  while (getline(file, str)) {

    if (str.length() > 2)
      { string_parser(str); }

    if (str.length() <= 1) {
        if (is_valid())
          { valid_ones++; }

        reset_map();
    }

  }
  if (is_valid())
    { valid_ones++; }

  cout << valid_ones << endl;
}
