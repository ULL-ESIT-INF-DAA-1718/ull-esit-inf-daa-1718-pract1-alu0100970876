#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class InputTape{
  int index;
public:
  vector<int> inputtape;

  InputTape(); 

  InputTape(string fileName); 

  int read(void);
};
