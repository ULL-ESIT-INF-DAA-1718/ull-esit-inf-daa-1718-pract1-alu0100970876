#include "OutputUnit.h"

  void OutputUnit::write(float data){
    tape.write(data);
  }

  void OutputUnit::toFile(string fileName){
    tape.toFile(fileName);
  }
