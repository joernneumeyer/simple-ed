#include "line_node.hpp"
#include <iostream>

lib::line_node::line_node(const string& str)
  : content(str) {
}

lib::line_node* lib::line_node::get_next() const {
  return this->next;
}

void lib::line_node::set_next(lib::line_node* next) {
  this->next = next;
}

void lib::line_node::print_line() const {
  this->content.print();
  std::cout << std::endl;
}

const lib::string& lib::line_node::get_content() const {
  return this->content;
}

void lib::line_node::set_content(const lib::string& content) {
  this->content = content;
}
