#pragma once

namespace lib {
  class editor_command {
  public:
    virtual void run(text_list& list, unsigned long int line = -1) = 0;
  };
};
