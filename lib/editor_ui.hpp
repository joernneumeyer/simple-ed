#pragma once
#include "text_list.hpp"

namespace lib {
  class editor_ui {
  private:
    text_list list;
  public:
    editor_ui();
    editor_ui(const char* input_file);

    void start();
  };
};
