#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

/**
 * \class OutputTape
 *
 *
 * \brief Clase que implementa la cinta de salida de la maquina ram
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class OutputTape{
public:
  vector<int> outputtape;

/** \brief Constructor por defecto
  * 
  * Este metodo instancia un objeto da la clase OutputTape
  */
  OutputTape(); 

/** \brief write
  * 
  * \param int data entero a escribir en la cinta de salida
  *
  * Este metodo escribe un valor en la cinta de salida
  */
  void write(int data);

/** \brief toFile
  * 
  * \param string fileName nombre del fichero donde volcar la cinta
  *
  * Este metodo vuelca en un fichero dado la cinta de salida
  */
  void toFile(string fileName);
};
