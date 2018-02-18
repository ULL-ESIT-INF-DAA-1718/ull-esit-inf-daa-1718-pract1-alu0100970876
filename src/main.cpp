#include "ControlUnit.h"

int main(int argc, char* argv[]){
  if(argc < 5){
   cout << "Numero de argumentos incorrecto" << endl;
  }
  else{
    ControlUnit maquinaram = ControlUnit(string(argv[1]), string(argv[2]), string(argv[3]));
    if(string(argv[4]) == "debug"){
      cout << "Debug mode" << endl;
      maquinaram.compute(true);
    }
    else{
      maquinaram.compute(false);
    }
  }
}
