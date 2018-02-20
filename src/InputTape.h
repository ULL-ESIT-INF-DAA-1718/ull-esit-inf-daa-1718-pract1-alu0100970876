#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

/**
 * \class InputaTape
 *
 *
 * \brief Clase que implementa la cinta de entrada de la maquina ram
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class InputTape{
  int index;
public:
  vector<float> inputtape;

/** \brief Constructor por defecto
  * 
  * Este metodo instancia un objeto da la clase InputTape
  */
  InputTape(); 

/** \brief Constructor
  * 
  * Este metodo instancia un objeto da la clase InputTape cargando su memoria de un fichero
  *
  * /param  string filename nombre del fichero de donde se carga la cinta
  */
  InputTape(string fileName); 

/** \brief read
  * 
  * Este metodo retorna el correspondiente elemento de la cinta de entrada
  *
  * /return int dato
  */
  float read(void);
};
