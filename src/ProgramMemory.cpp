#include "ProgramMemory.h"

  Instruccion::Instruccion(int a, string b, int c){
    ident = a;
    value = b;
    linea = c;
  }  

  void ProgramMemory::addInstruccion(int ident, string value, int linea){
    this->programmem.push_back(Instruccion(ident, value, linea));
  }    

  Instruccion ProgramMemory::read(int pos){
    return this->programmem[pos];
  }
