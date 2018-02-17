#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class InputTape{
  int index;
  vector<int> inputtape;
public:
  InputTape(); 

  InputTape(string fileName); 

  int read(void);
};
