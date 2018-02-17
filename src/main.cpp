#include "ControlUnit.h"

int main(void){
  ControlUnit maquinaram = ControlUnit("test1.ram", "input.in", "output.out");
  for(int i = 0; i < maquinaram.progmem.programmem.size(); i++)
    cout << maquinaram.progmem.programmem[i].ident << " " << maquinaram.progmem.programmem[i].value << " " << maquinaram.progmem.programmem[i].linea << endl;
  /*for(int i = 0; i < maquinaram.etiquetas.size(); i++)
    cout << maquinaram.etiquetas[i].nombre << " " << maquinaram.etiquetas[i].fila << endl;*/
}
