#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class OutputTape{
  vector<int> outputtape;
public:
  OutputTape(); 

  void write(int data);

  void toFile(string fileName);
};
