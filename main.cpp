#include "lib/editor_ui.hpp"
#include "lib/string.hpp"
//#include <iostream>
//#include <string>

int main(const int argc, const char** argv) {
  if (argc == 2) {
    lib::editor_ui(argv[1]).start();
  }
  lib::editor_ui().start();
}
