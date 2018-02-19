#include "InputTape.h"

/**
 * \class InputUnit
 *
 *
 * \brief Clase wrapper para un objeto de la clase InputTape
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class InputUnit{
public:
  InputTape tape;
 
/** \brief Constructor por defecto
  * 
  * Este metodo instancia un objeto da la clase InputUnit
  */
  InputUnit();

/** \brief Constructor
  * 
  * Este metodo instancia un objeto da la clase InputUnit cargando su memoria de un fichero
  *
  * /param  string filename nombre del fichero de donde se carga la cinta
  */
  InputUnit(string file);

/** \brief read
  * 
  * Este metodo retorna el correspondiente elemento de la cinta de entrada
  *
  * /return int dato
  */
  int read();
};
