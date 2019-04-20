#include <iostream>
#include <fstream>

#include "editor_ui.hpp"

lib::editor_ui::editor_ui() {
}

lib::editor_ui::editor_ui(const char* input_file) {
  std::ifstream fs(input_file);
  if (!fs.is_open()) return;
  std::string line;
  while (!fs.eof()) {
    std::getline(fs, line);
    this->list.append_line(line.c_str());
  }
  fs.close();
}

void lib::editor_ui::start() {
  while (true) {
    std::cout << '*';
    std::string line;
    std::getline(std::cin, line);
    if (line.size() == 0) continue;
    size_t line_number = 0;
    if (line.size() > 1) {
      line_number = atol(line.c_str() + 1);
    }
    switch (line[0]) {
      case 'a':
        std::getline(std::cin, line);
        this->list.append_line(line.c_str());
        break;
      case 'p':
        if (line_number) {
          this->list.print_line(line_number);
        } else {
          this->list.print_all();
        }
        break;
      case 'i':
        std::getline(std::cin, line);
        this->list.insert_line(line.c_str(), line_number);
        break;
      case 'd':
        if (line_number == 0) continue;
        this->list.delete_line(line_number);
        break;
      case 'x':
        std::getline(std::cin, line);
        this->list.extend_line(line.c_str(), line_number);
        break;
      case 's':
        std::getline(std::cin, line);
        std::ofstream os(line.c_str());
        if (!os.is_open()) continue;
        auto a = std::cin;
        std::cin = os;
        this->list.print_all();
        os.close();
        std::cin = a;
        break;
    }
  }
}
