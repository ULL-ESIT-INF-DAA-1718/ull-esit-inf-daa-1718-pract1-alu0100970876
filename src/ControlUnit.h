#pragma once
#include "DataMemory.h"
#include "ProgramMemory.h"
#include "InputUnit.h"
#include "OutputUnit.h"
#include <regex>
#include <sstream>
#include <unistd.h>

class Etiqueta{
public:
  string nombre;
  int fila;
  Etiqueta(string name, int num);
};

class ControlUnit{
  public://private: publico mientras se depura
    int ip; //instruction pointer
    DataMemory datamem;
    ProgramMemory progmem;
    InputUnit inputunit;
    OutputUnit outputunit;
    string out;
    vector<Etiqueta> etiquetas;

    void loadProgmem(string filename);
 
  public:
 
    ControlUnit(string progmem, string inputtape, string outputtape);

    void compute(bool option);
};
