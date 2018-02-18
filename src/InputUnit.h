#include "InputTape.h"

class InputUnit{
public:
  InputTape tape;
 
  InputUnit();
  InputUnit(string file);

  int read();
};
