#include <fstream>
#include "ElemL1.h"
using namespace std;
void inputSLC(fstream& f, R_Channel** p);
void inputSLA(fstream& f, ads** p);
bool inputSL(fstream& f, strlenght& SL);
void outputSL(fstream& of, struct strlenght SL);
void outputSLcosole(fstream& of, strlenght SL);