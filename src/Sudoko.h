#include <iostream>
const int puzzleDim = 9;    // puzzleDim x puzzleDim puzzle dimension

using namespace std;

class puzzle{
    public:
        int numMatrix[puzzleDim][puzzleDim];    // puzzle matrix
        
        puzzle(){   // constructor that executes at object creation
            cout << "This is printed automatically" << "\n\n";
            acceptInput(numMatrix);
            printPuzzle(numMatrix);
        }

        // function that accepts the 
        void acceptInput(int puzzleArray[][puzzleDim]){
            for(int i = 0; i < puzzleDim; i++){
                for(int j = 0; j < puzzleDim; j++){
                    cout << "Enter the row " << i + 1 << " column " << j + 1 << "entry:\n";
                    cin >> puzzleArray[i][j];
                }    
            }
            
        }

        void validatePuzzle(){

        }
        void printPuzzle(int puzzleArray[][puzzleDim]){
            for(int i = 0; i < puzzleDim; i++){
                for(int j = 0; j < puzzleDim; j++){
                    cout << puzzleArray[i][j] << " ";
                }  
                cout << "\n";
            }
        }         
};