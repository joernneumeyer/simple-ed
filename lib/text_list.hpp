#pragma once
#include "line_node.hpp"

namespace lib {
  class text_list {
  private:
    line_node* head = new line_node("");
    line_node* tail = new line_node("");
    line_node* runner = nullptr;
    size_t number_of_lines = 0;

    void set_runner(size_t line);
  public:
    text_list();
    virtual ~text_list();
    void append_line(const string& str);
    void print_all();
    void print_line(const size_t line);
    size_t get_number_of_lines() const;
    void insert_line(const string& str, const size_t position);
    void delete_line(const size_t position);
    void extend_line(const string& str, const size_t line);
  };
};
