#include "string.hpp"
#include <iostream>

lib::string::string(const char* str) {
  this->length = strlen(str);
  this->str = new char[this->length + 1];
  strcpy(this->str, str);
}

lib::string::string(const string& str) {
  this->length = str.length;
  this->str = new char[this->length + 1];
  strcpy(this->str, str.str);
}

lib::string::~string() {
  delete[] this->str;
}

size_t lib::string::get_length() const {
  return this->length;
}

void lib::string::print() const {
  std::cout << this->str;
}

lib::string lib::string::operator+(const lib::string& str) const {
  char* combined = new char[this->length + str.length + 1];
  strcpy(combined, this->str);
  strcpy(&combined[this->length], str.str);
  lib::string result(combined);
  delete[] combined;
  return result;
}
