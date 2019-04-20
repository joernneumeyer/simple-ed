#pragma once
#include <cstring>

namespace lib {
  class string {
    char* str;
    size_t length;

  public:
    string(const char* str);
    string(const string& str);
    // string(string&& str); // TODO
    virtual ~string();

    void print() const;
    size_t get_length() const;
    string operator+(const string& str) const;
  };
};
