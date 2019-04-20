#pragma once
#include "string.hpp"

namespace lib {
  class line_node {
  private:
    line_node* next = nullptr;
    lib::string content;
  public:
    line_node(const lib::string& str);
    line_node* get_next() const;
    void set_next(lib::line_node* next);
    void print_line() const;
    const lib::string& get_content() const;
    void set_content(const lib::string& str);
  };
};
