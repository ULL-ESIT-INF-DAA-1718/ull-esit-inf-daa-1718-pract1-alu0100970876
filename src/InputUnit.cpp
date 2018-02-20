#include "InputUnit.h"

InputUnit::InputUnit(){}

InputUnit::InputUnit(string file){
  tape = InputTape(file);
}

float InputUnit::read(){
  return tape.read();
}
