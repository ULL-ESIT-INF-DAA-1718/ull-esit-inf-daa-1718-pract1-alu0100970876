#include "InputTape.h"

	InputTape::InputTape(){
		  index = 0;
		}

  InputTape::InputTape(string fileName){
    index = 0;
    fstream myfile(fileName.c_str());
    int dummy;
    while(myfile >> dummy)
      inputtape.push_back(dummy);
  } 

  int InputTape::read(void){
    int temp = index;
    index++;
    return inputtape[temp];
  }
