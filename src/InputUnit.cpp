#include "InputUnit.h"

InputUnit::InputUnit(){}

InputUnit::InputUnit(string file){
  tape = InputTape(file);
}

int InputUnit::read(){
  return tape.read();
}
