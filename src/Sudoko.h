#include <iostream>
const int puzzleDim = 9;    // n x n puzzle dimension

using namespace std;

class puzzle{
    public:
        int numMatrix[puzzleDim][puzzleDim];    // puzzle matrix
        puzzle(){
            cout << "This is printed automatically" << "\n";
        }
};