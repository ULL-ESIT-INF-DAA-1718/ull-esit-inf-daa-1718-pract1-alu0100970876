#include "ControlUnit.h"

Etiqueta::Etiqueta(string name, int num){
  nombre = name;
  fila = num;
}

/*
LOAD op  El operando se carga en R 0 (1 cte | 2 directo | 3 indirecto)
STORE op  El contenido de R 0 se almacena en la memoria según el operando (4 cte | 5 directo | 6 indirecto)
ADD op  El operando se suma a R 0 y el resultado se almacena en R 0 (7 cte | 8 directo | 9 indirecto)
SUB op  El operando se resta a R 0 y el resultado se almacena en R 0 (10 cte | 11 directo | 12 indirecto)
MUL op  El operando multiplica a R 0 y el resultado se almacena en R 0 (13 cte | 14 directo | 15 indirecto)
DIV op  El operando divide a R 0 y el resultado se almacena en R 0 (16 cte | 17 directo | 18 indirecto)
READ op  Se lee un valor de la cinta de entrada y se almacena en la memoria según el operando (19 cte | 20 directo | 21 indirecto)
WRITE op  Se escribe el operando en la cinta de salida (22 cte | 23 directo | 24 indirecto)
JUMP etiq  El valor del registro IP se modifica para apuntar a la instrucción  identificada por la etiqueta (25)
JZERO etiq El valor del registro IP se modifica para apuntar a la instrucción identificada por la etiqueta (si R 0 == 0) (26)
JGTZ etiq El valor del registro IP se modifica para apuntar a la instrucción identificada por la etiqueta (si R 0 > 0) (27)
HALT  Detiene la ejecución del programa (28)
*/

void ControlUnit::loadProgmem(string filename){
    
    int l_counter = 0;
    int instruccion;
    int data;
    fstream myfile(filename.c_str());
    string dummy;
    while(!myfile.eof()){
      l_counter++;
      getline(myfile, dummy);
      if(!regex_match(dummy, regex("#.*"))){//si no es un comentario
        vector<string> instruccion;
        istringstream iss(dummy);
        do{//se separa a instruccion es sus partes
          string subs;
          iss >> subs;
          instruccion.push_back(subs);
        }while (iss);
        instruccion.pop_back();
        if(instruccion.size() == 3){
          //tiene etiqueta
          instruccion[0].pop_back();//se le quita los : a la etiqueta
          etiquetas.push_back(Etiqueta(instruccion[0], l_counter));
          //comprobacion del tipo y creacion de la instruccion
          if(instruccion[1] == "LOAD" || instruccion[1] == "load"){
            if(instruccion[2][0] == '='){
              progmem.addInstruccion(1, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else if(instruccion[2][0] == '*'){
              progmem.addInstruccion(3, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(2, instruccion[2], l_counter);
            }
          }
          else if(instruccion[1] == "STORE" || instruccion[1] == "store"){
            if(instruccion[2][0] == '='){
							cout << "Error en la linea " << l_counter << " =i no es valido en store" << endl;
          		exit(0);
              progmem.addInstruccion(4, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else if(instruccion[2][0] == '*'){
              progmem.addInstruccion(6, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(4, instruccion[2], l_counter);
            }
          }
          else if(instruccion[1] == "ADD" || instruccion[1] == "add"){
            if(instruccion[2][0] == '='){
              progmem.addInstruccion(7, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else if(instruccion[2][0] == '*'){
              progmem.addInstruccion(9, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(8, instruccion[2], l_counter);
            }
          }
          else if(instruccion[1] == "SUB" || instruccion[1] == "sub"){
            if(instruccion[2][0] == '='){
              progmem.addInstruccion(10, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else if(instruccion[2][0] == '*'){
              progmem.addInstruccion(12, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(11, instruccion[2], l_counter);
            }
          }
          else if(instruccion[1] == "MUL" || instruccion[1] == "mul"){
            if(instruccion[2][0] == '='){
              progmem.addInstruccion(13, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else if(instruccion[2][0] == '*'){
              progmem.addInstruccion(15, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(14, instruccion[2], l_counter);
            }
          }
          else if(instruccion[1] == "DIV" || instruccion[1] == "div"){
            if(instruccion[2][0] == '='){
              progmem.addInstruccion(16, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else if(instruccion[2][0] == '*'){
              progmem.addInstruccion(18, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(17, instruccion[2], l_counter);
            }
          }
          else if(instruccion[1] == "READ" || instruccion[1] == "read"){
            if(instruccion[2][0] == '='){
              cout << "Error en la linea " << l_counter << " =i no es valido en read" << endl;
          		exit(0);
              progmem.addInstruccion(19, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else if(instruccion[2][0] == '*'){
              progmem.addInstruccion(21, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(19, instruccion[2], l_counter);
            }
          }
          else if(instruccion[1] == "WRITE" || instruccion[1] == "write"){
            if(instruccion[2][0] == '='){
              progmem.addInstruccion(22, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else if(instruccion[2][0] == '*'){
              progmem.addInstruccion(24, instruccion[2].substr(1, instruccion[2].size() - 1), l_counter);
            }
            else{
              if(instruccion[1][0]  == '0'){
                cout << "Error en la linea " << l_counter << " write 0 no es valido en read" << endl;
          		  exit(0);
              }
              progmem.addInstruccion(23, instruccion[2], l_counter);
            }
          }
          else if(instruccion[1] == "JUMP" || instruccion[1] == "jump"){
            progmem.addInstruccion(25, instruccion[2], l_counter);
          }
          else if(instruccion[1] == "JZERO" || instruccion[1] == "jzero"){
            progmem.addInstruccion(26, instruccion[2], l_counter);
          }
          else if(instruccion[1] == "JGTZ" || instruccion[1] == "jgtz"){
            progmem.addInstruccion(27, instruccion[2], l_counter);
          }
          else{
            cout << "Instruccion no valida: \"" << instruccion[0] << " " << instruccion[1] << " " << instruccion[2] << "\" En la línea: " << l_counter << endl;
            exit(0);
          }
          //nunca se dará el caso de halt con 3 argunmentos en la linea
        }
        else if (instruccion.size() > 3){
          cout << "Error en la linea " << l_counter << " Numero de argumentos erróneo" << endl;
          exit(0);
        }
        else if (instruccion.size() == 0){}
        else{
         //no tiene etiqueta o es halt con etiqueta
          if(instruccion[0] == "LOAD" || instruccion[0] == "load"){
            if(instruccion[1][0] == '='){
              progmem.addInstruccion(1, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else if(instruccion[1][0] == '*'){
              progmem.addInstruccion(3, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(2, instruccion[1], l_counter);
            }
          }
          else if(instruccion[0] == "STORE" || instruccion[0] == "store"){
            if(instruccion[1][0] == '='){
							cout << "Error en la linea " << l_counter << " =i no es valido en store" << endl;
          		exit(0);
              progmem.addInstruccion(4, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else if(instruccion[1][0] == '*'){
              progmem.addInstruccion(6, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(4, instruccion[1], l_counter);//progmem.addInstruccion(5, instruccion[1], l_counter);
            }
          }
          else if(instruccion[0] == "ADD" || instruccion[0] == "add"){
            if(instruccion[1][0] == '='){
              progmem.addInstruccion(7, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else if(instruccion[1][0] == '*'){
              progmem.addInstruccion(9, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(8, instruccion[1], l_counter);
            }
          }
          else if(instruccion[0] == "SUB" || instruccion[0] == "sub"){
            if(instruccion[1][0] == '='){
              progmem.addInstruccion(10, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else if(instruccion[1][0] == '*'){
              progmem.addInstruccion(12, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(11, instruccion[1], l_counter);
            }
          }
          else if(instruccion[0] == "MUL" || instruccion[0] == "mul"){
            if(instruccion[1][0] == '='){
              progmem.addInstruccion(13, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else if(instruccion[1][0] == '*'){
              progmem.addInstruccion(15, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(14, instruccion[1], l_counter);
            }
          }
          else if(instruccion[0] == "DIV" || instruccion[0] == "div"){
            if(instruccion[1][0] == '='){
              progmem.addInstruccion(16, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else if(instruccion[1][0] == '*'){
              progmem.addInstruccion(18, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else{
              progmem.addInstruccion(17, instruccion[1], l_counter);
            }
          }
          else if(instruccion[0] == "READ" || instruccion[0] == "read"){
            if(instruccion[1][0] == '='){
              cout << "Error en la linea " << l_counter << " =i no es valido en read" << endl;
          		exit(0);
              progmem.addInstruccion(19, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else if(instruccion[1][0] == '*'){

              progmem.addInstruccion(21, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else{
              if(instruccion[1].substr(1, instruccion[1].size() - 1) == "0"){
                cout << "Error en la linea " << l_counter << " read 0 no es valido en read" << endl;
          		  exit(0);
              }
              progmem.addInstruccion(19, instruccion[1], l_counter);//progmem.addInstruccion(20, instruccion[1], l_counter);
            }
          }
          else if(instruccion[0] == "WRITE" || instruccion[0] == "write"){
            if(instruccion[1][0] == '='){
              progmem.addInstruccion(22, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else if(instruccion[1][0] == '*'){
              progmem.addInstruccion(24, instruccion[1].substr(1, instruccion[1].size() - 1), l_counter);
            }
            else{
              if(instruccion[1][0]  == '0'){
                cout << "Error en la linea " << l_counter << " write 0 no es valido en read" << endl;
          		  exit(0);
              }
              progmem.addInstruccion(23, instruccion[1], l_counter);
            }
          }
          else if(instruccion[0] == "JUMP" || instruccion[0] == "jump"){
            progmem.addInstruccion(25, instruccion[1], l_counter);
          }
          else if(instruccion[0] == "JZERO" || instruccion[0] == "jzero"){
            progmem.addInstruccion(26, instruccion[1], l_counter);
          }
          else if(instruccion[0] == "JGTZ" || instruccion[0] == "jgtz"){
            progmem.addInstruccion(27, instruccion[1], l_counter);
          }
          else if(instruccion[0] == "HALT" || instruccion[0] == "halt"){
            progmem.addInstruccion(28, "", l_counter);
          }
          else{
            if(instruccion[1] == "HALT" || instruccion[1] == "halt"){
              instruccion[0].pop_back();//se le quita los : a la etiqueta
              etiquetas.push_back(Etiqueta(instruccion[0], l_counter));
              progmem.addInstruccion(28, "", l_counter);
            }
            else{
		          cout << "Instruccion no valida: \"" << dummy << "\" En la línea: " << l_counter << endl;
		          exit(0);
            }
          }
        }
      }         
    }    
}

ControlUnit::ControlUnit(string progmem, string inputtape, string outputtape){
  ip = 0;
  out = outputtape;
  inputunit = InputUnit(inputtape);
  loadProgmem(progmem);
  datamem.memoria.resize(1000);
}
/*
LOAD op  El operando se carga en R 0 (1 cte | 2 directo | 3 indirecto)
STORE op  El contenido de R 0 se almacena en la memoria según el operando (4 cte | 5 directo | 6 indirecto)
ADD op  El operando se suma a R 0 y el resultado se almacena en R 0 (7 cte | 8 directo | 9 indirecto)
SUB op  El operando se resta a R 0 y el resultado se almacena en R 0 (10 cte | 11 directo | 12 indirecto)
MUL op  El operando multiplica a R 0 y el resultado se almacena en R 0 (13 cte | 14 directo | 15 indirecto)
DIV op  El operando divide a R 0 y el resultado se almacena en R 0 (16 cte | 17 directo | 18 indirecto)
READ op  Se lee un valor de la cinta de entrada y se almacena en la memoria según el operando (19 cte | 20 directo | 21 indirecto)
WRITE op  Se escribe el operando en la cinta de salida (22 cte | 23 directo | 24 indirecto)
JUMP etiq  El valor del registro IP se modifica para apuntar a la instrucción  identificada por la etiqueta (25)
JZERO etiq El valor del registro IP se modifica para apuntar a la instrucción identificada por la etiqueta (si R 0 == 0) (26)
JGTZ etiq El valor del registro IP se modifica para apuntar a la instrucción identificada por la etiqueta (si R 0 > 0) (27)
HALT  Detiene la ejecución del programa (28)
*/
void ControlUnit::compute(bool option){
  Instruccion dummy;
  int contador = 0;
  bool next = true;
  do{
    dummy = progmem.programmem[ip];
    if(option){
      cout << "-----------------------------------------------------------" << endl;
      cout << "Instruction pointer: " << ip << endl;
      cout << "Memoria de programa " << endl;
      for(int i = 0; i < progmem.programmem.size(); i++){
        cout << i <<  " ->Instruccion: " <<  progmem.programmem[i].ident << " Valor: " << progmem.programmem[i].value << " Linea: " << progmem.programmem[i].linea << endl;
      }
      cout << "Memoria de datos" << endl;
      for(int i = 0; i < 10; i++){
        cout << i << " -> " << datamem.memoria[i] << endl;
      }
      cout << "Cinta de entrada" << endl;
      for(int i = 0; i < inputunit.tape.inputtape.size(); i++){
        cout << inputunit.tape.inputtape[i] << " ";
      }
      cout << endl;
      cout << "Cinta de Salida" << endl;
      for(int i = 0; i < outputunit.tape.outputtape.size(); i++){
        cout << outputunit.tape.outputtape[i] << " ";
      }
      cout << endl;
      usleep(500000);
    } 
    switch(dummy.ident){
      case 1://load----------------------
        datamem.memoria[0] = stoi(dummy.value);
        ip++;
        break;
      case 2:
        datamem.memoria[0] = datamem.memoria[stoi(dummy.value)];
        ip++;
        break;
      case 3:
        datamem.memoria[0] = datamem.memoria[datamem.memoria[stoi(dummy.value)]];
        ip++;
        break;
      case 4://store------------
        datamem.memoria[stoi(dummy.value)] = datamem.memoria[0];
        ip++;
        break;
      case 5:
        datamem.memoria[datamem.memoria[stoi(dummy.value)]] = datamem.memoria[0];
        ip++;
        break;
      case 6:
        datamem.memoria[datamem.memoria[stoi(dummy.value)]] = datamem.memoria[0];//datamem.memoria[datamem.memoria[datamem.memoria[stoi(dummy.value)]]] = datamem.memoria[0];
        ip++;
        break;
      case 7://add-----------------------
        datamem.memoria[0] = datamem.memoria[0] + stoi(dummy.value);
        ip++;
        break;
      case 8:
        datamem.memoria[0] = datamem.memoria[0] + datamem.memoria[stoi(dummy.value)];
        ip++;
        break;
      case 9:
        datamem.memoria[0] = datamem.memoria[0] + datamem.memoria[datamem.memoria[stoi(dummy.value)]];
        ip++;
        break;
      case 10://sub-------------------------
        datamem.memoria[0] = datamem.memoria[0] - stoi(dummy.value);
        ip++;
        break;
      case 11:
        datamem.memoria[0] = datamem.memoria[0] - datamem.memoria[stoi(dummy.value)];
        ip++;
        break;
      case 12:
        datamem.memoria[0] = datamem.memoria[0] - datamem.memoria[datamem.memoria[stoi(dummy.value)]];
        ip++;
        break;
      case 13://mul--------------------------
        datamem.memoria[0] = datamem.memoria[0] * stoi(dummy.value);
        ip++;
        break;
      case 14:
        datamem.memoria[0] = datamem.memoria[0] * datamem.memoria[stoi(dummy.value)];
        ip++;
        break;
      case 15:
        datamem.memoria[0] = datamem.memoria[0] * datamem.memoria[datamem.memoria[stoi(dummy.value)]];
        ip++;
        break;
      case 16://div--------------------
        datamem.memoria[0] = datamem.memoria[0] / stoi(dummy.value);
        ip++;
        break;
      case 17:
       datamem.memoria[0] = datamem.memoria[0] / datamem.memoria[stoi(dummy.value)];
        ip++;
        break;
      case 18:
        datamem.memoria[0] = datamem.memoria[0] / datamem.memoria[datamem.memoria[stoi(dummy.value)]];
        ip++;
        break;
      case 19://read----------------
        datamem.memoria[stoi(dummy.value)] = inputunit.read();
        ip++;
        break;
      case 20:
        datamem.memoria[datamem.memoria[stoi(dummy.value)]] = inputunit.read();
        ip++;
        break;
      case 21:
        datamem.memoria[datamem.memoria[stoi(dummy.value)]] = inputunit.read();//datamem.memoria[datamem.memoria[datamem.memoria[stoi(dummy.value)]]] = inputunit.read();
        ip++;
        break;
      case 22://write----------------------
        outputunit.write(stoi(dummy.value));
        ip++;
        break;
      case 23:
        outputunit.write(datamem.memoria[stoi(dummy.value)]);
        ip++;
        break;
      case 24:
        outputunit.write(datamem.memoria[datamem.memoria[stoi(dummy.value)]]);
        ip++;
        break;
      case 25:{//jump--------------
        int lineadummy = dummy.linea;
        for(int i = 0; i < etiquetas.size(); i++){
           if(etiquetas[i].nombre == dummy.value){
             lineadummy = etiquetas[i].fila;
           }
        }
        for(int i = 0; i < progmem.programmem.size(); i++){
          if(progmem.programmem[i].linea == lineadummy){
            ip = i;
          }
        }
        break;
       }
      case 26:{//jzero-----------------
        if(datamem.memoria[0] == 0){
          int lineadummy = dummy.linea;
		      for(int i = 0; i < etiquetas.size(); i++){
		         if(etiquetas[i].nombre == dummy.value){
		           lineadummy = etiquetas[i].fila;
		         }
		      }
		      for(int i = 0; i < progmem.programmem.size(); i++){
		        if(progmem.programmem[i].linea == lineadummy){
		          ip = i;
		        }
		      }
        }
        else{
          ip++;
        }
        break;
      }
      case 27://jgtz-------------------
        if(datamem.memoria[0] > 0){
          int lineadummy = dummy.linea;
		      for(int i = 0; i < etiquetas.size(); i++){
		         if(etiquetas[i].nombre == dummy.value){
		           lineadummy = etiquetas[i].fila;
		         }
		      }
		      for(int i = 0; i < progmem.programmem.size(); i++){
		        if(progmem.programmem[i].linea == lineadummy){
		          ip = i;
		        }
		      }
        }
        else{
          ip++;
        }
        break;
      case 28://halt-------------------
        next = false;
        break;
      default:
        next = false;
    }
    contador++;
  }while(next);
  outputunit.toFile(out);
  if(!option){
    cout << "Numero de instrucciones ejecutadas: " << contador << endl;
  }
}


