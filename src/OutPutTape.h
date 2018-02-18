#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class OutputTape{
public:
  vector<int> outputtape;
  OutputTape(); 

  void write(int data);

  void toFile(string fileName);
};
