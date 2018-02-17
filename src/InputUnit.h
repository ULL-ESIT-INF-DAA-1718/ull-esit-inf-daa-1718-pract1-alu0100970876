#include "InputTape.h"

class InputUnit{
  InputTape tape;
public: 
  InputUnit();
  InputUnit(string file);

  int read();
};
