#include "OutPutTape.h"

class OutputUnit{
  OutputTape tape;
public: 
  void write(int data);

  void toFile(string fileName);
};
