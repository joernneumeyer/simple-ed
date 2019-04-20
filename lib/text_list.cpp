#include "text_list.hpp"

lib::text_list::text_list() {
  this->head->set_next(this->tail);
}

lib::text_list::~text_list() {
  this->runner = this->head;
  lib::line_node* p;
  while (this->runner != nullptr) {
    p = this->runner->get_next();
    delete this->runner;
    this->runner = p;
  }
}

void lib::text_list::set_runner(const size_t line) {
  this->runner = this->head;
  for (size_t i = 0; i <= line; ++i) {
    this->runner = this->runner->get_next();
  }
}

void lib::text_list::delete_line(const size_t line) {
  this->set_runner(line - 1);
  lib::line_node* p = this->runner->get_next();
  this->runner->set_next(this->runner->get_next()->get_next());
  delete p;
}

void lib::text_list::extend_line(const string& str, const size_t line = 0) {
  if (line == 0) return;
  this->set_runner(line);
  this->runner->set_content(this->runner->get_content() + str);
}

void lib::text_list::append_line(const string& str) {
  const auto next = new lib::line_node(str);
  this->tail->set_next(next);
  this->tail = next;
  this->set_runner(this->number_of_lines++);
}

void lib::text_list::print_line(const size_t line) {
  this->set_runner(line);
  this->runner->print_line();
}

void lib::text_list::print_all() {
  this->set_runner(1);
  auto p = this->runner;
  while (p != nullptr) {
    p->print_line();
    p = p->get_next();
  }
}

size_t lib::text_list::get_number_of_lines() const {
  return this->number_of_lines;
}

void lib::text_list::insert_line(const string& str, const size_t position = 0) {
  if (position == 0) {
    const auto next = new lib::line_node(str);
    next->set_next(this->runner->get_next());
    this->runner->set_next(next);
    return;
  }
  this->set_runner(position - 1);
  this->insert_line(str, 0);
}
