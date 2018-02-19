#pragma once
#include "DataMemory.h"
#include "ProgramMemory.h"
#include "InputUnit.h"
#include "OutputUnit.h"
#include <regex>
#include <sstream>
#include <unistd.h>

/**
 * \class Etiqueta
 *
 *
 * \brief Clase que uso para almacenar las etiquetas y a que linea hacen referencia
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class Etiqueta{
public:
  string nombre;
  int fila;

/** \brief Constructor
  * 
  * Este metodo instancia un objeto da la clase Etiqueta
  *
  * /param name string nombre de la etiqueta
  * /param num int que referencia a la linea
  */
  Etiqueta(string name, int num);
};

/**
 * \class ControlUnit
 *
 * \brief Clase en la que se implementa la unidad de control de la maquina ram
 *
 * \author Miguel Jiménez Gomis
 *
 * Contact: alu0100970876@ull.edu.es
 *
 */
class ControlUnit{
  public://private: publico mientras se depura
    int ip; //instruction pointer
    DataMemory datamem;
    ProgramMemory progmem;
    InputUnit inputunit;
    OutputUnit outputunit;
    string out;
    vector<Etiqueta> etiquetas;

/** \brief loadProgmem
  * \param string filename nombre del fichero donde se encuentra el programa
  * 
  * Este metodo analiza el fichero donde esta guardado el programay lo va almacenando en la memoria del programa si es correcto
  */
    void loadProgmem(string filename);
 
  public:
 
/** \brief Constructor
  * \param string progmem fichero donde se encuentra la memoria del programa
  * \param string inputtape fichero donde se guarda la cinta de entrada
  * \param string outputtape fichero donde se guarda la cinta de salida 
  * 
  * Este metodo instancia un objeto de la clase ControlUnit
  */
    ControlUnit(string progmem, string inputtape, string outputtape);

/** \brief Compute
  * \param bool option Opcion de Debug(1) o normal(0)
  * 
  * Este metodo ejecuta el programa una vez ha sido cargado en memoria
  */
    void compute(bool option);
};
