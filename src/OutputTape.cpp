#include "OutPutTape.h"

  OutputTape::OutputTape(){
  } 

  void OutputTape::write(int data){
    outputtape.push_back(data);
  }

  void OutputTape::toFile(string fileName){
    ofstream myfile;
    myfile.open(fileName.c_str());
    for(int i = 0; i < outputtape.size(); i++)
      myfile << outputtape[i] << " ";
    myfile.close();
  }
