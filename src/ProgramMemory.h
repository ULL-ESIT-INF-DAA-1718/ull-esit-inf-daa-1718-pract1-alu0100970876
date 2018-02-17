#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Instruccion{
 public:
   int ident;// entero que identifica el tipo de instruccion
   string value;//valor de la instruccion
   int linea;//linea del programa donde se encuentra

  Instruccion(int a, string b, int c);
};

class ProgramMemory{
  public:
    vector<Instruccion> programmem;
    
    void addInstruccion(int ident, string value, int linea);    

    Instruccion read(int pos);
};
