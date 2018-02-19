#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * \class Instruccion
 *
 *
 * \brief Clase que representa una instruccion de mi set de instrucciones particular
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class Instruccion{
 public:
   int ident;// entero que identifica el tipo de instruccion
   string value;//valor de la instruccion
   int linea;//linea del programa donde se encuentra

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

/** \brief contructor por defecto
  *
  * Este metodo instancia un objeto vacio de la clase Instruccion
  */
  Instruccion();

/** \brief Constructor
  * 
  * \param int a identificador
  * \param string b valor
  * \param int c linea del fichero en el que está
  * Este metodo instancia un objeto de la clase Instruccion
  */
  Instruccion(int a, string b, int c);
};

/**
 * \class ProgramMemory
 *
 *
 * \brief Clase que implementa la memoria de programa de la maquina ram
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class ProgramMemory{
  public:
    vector<Instruccion> programmem;
    
/** \brief addInstruccion
  * 
  * \param int ident identificador
  * \param string value valor
  * \param int linea linea del fichero en el que está
  * Añade a la memoria una instruccion con esos valores
  */
    void addInstruccion(int ident, string value, int linea);    

/** \brief read
  * 
  * \param int pos posicion de la instruccion en los registros
  *
  * \return Instruccion
  * Este metodo retorna la instruccion de una posicion determinada de la memoria
  */
    Instruccion read(int pos);
};
