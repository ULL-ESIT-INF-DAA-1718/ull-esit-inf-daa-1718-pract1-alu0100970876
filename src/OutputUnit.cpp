#include "OutputUnit.h"

  void OutputUnit::write(int data){
    tape.write(data);
  }

  void OutputUnit::toFile(string fileName){
    tape.toFile(fileName);
  }
