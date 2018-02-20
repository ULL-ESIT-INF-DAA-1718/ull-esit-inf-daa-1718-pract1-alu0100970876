#include "OutPutTape.h"

/**
 * \class OutPutUnit
 *
 *
 * \brief Clase wrapper para un objeto de la clase OutputTape
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class OutputUnit{
public:
  OutputTape tape;
 
/** \brief write
  * 
  * \param int data entero a escribir en la cinta de salida
  *
  * Este metodo escribe un valor en la cinta de salida
  */
  void write(float data);

/** \brief toFile
  * 
  * \param string fileName nombre del fichero donde volcar la cinta
  *
  * Este metodo vuelca en un fichero dado la cinta de salida
  */
  void toFile(string fileName);
};
