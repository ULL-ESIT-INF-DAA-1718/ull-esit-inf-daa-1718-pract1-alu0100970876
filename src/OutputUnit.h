#include "OutPutTape.h"

class OutputUnit{
public:
  OutputTape tape;
 
  void write(int data);

  void toFile(string fileName);
};
