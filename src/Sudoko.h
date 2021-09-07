#include <iostream>
#include <set>
const int puzzleDim = 9;    // [puzzleDim x puzzleDim] puzzle dimension

using namespace std;

class puzzle{
    public:
        int numMatrix[puzzleDim][puzzleDim];    // puzzle matrix
        int validity;                           // -1 if the puzzle contains an invalid value 
                                                // 0 if the puzzle contains repeated values
                                                // 1 if the puzzle is valid
        
        puzzle(){   // constructor that executes at object creation
            cout << "This is printed automatically" << "\n\n";
            acceptInput(numMatrix);
            validity = validatePuzzle(numMatrix);
        }

        // Function that accepts the array as reference and modifies it according to user's input.
        void acceptInput(int (&puzzleArray)[puzzleDim][puzzleDim]){
            for(int i = 0; i < puzzleDim; i++){
                for(int j = 0; j < puzzleDim; j++){
                    cout << "Enter the row " << i + 1 << " column " << j + 1 << " entry:\n";
                    cin >> puzzleArray[i][j];
                }    
            }
            
        }
        
        // Function that accepts the array and performs data cleaning. If data is valid, call printPuzzle.
        int validatePuzzle(int (&puzzleArray)[puzzleDim][puzzleDim]){
            set<int> s; // unique set of integers

            // check that all values are 0-9 
            for(int i = 0; i < puzzleDim; i++){
                for(int j = 0; j < puzzleDim; j++){
                    if(puzzleArray[i][j] < 0 || puzzleArray[i][j] > puzzleDim){
                        return -1;
                    }    
                }
                s.clear();  // clear the set s to allow new checks    
            }
            
            // check each row for duplicates in that row
            for(int i = 0; i < puzzleDim; i++){
                for(int j = 0; j < puzzleDim; j++){
                    if(puzzleArray[i][j] != 0){
                        if(s.insert(!puzzleArray[i][j]).second){
                            return 0;
                        }
                    }    
                }
                s.clear(); // clear the set s to allow new checks for each row    
            }    
            
            // check each column for duplicates in that column
            for(int i = 0; i < puzzleDim; i++){
                for(int j = 0; j < puzzleDim; j++){
                    if(puzzleArray[j][i] != 0){
                            if(s.insert(!puzzleArray[j][i]).second){
                                return 0;
                            }
                        } 
                }
                s.clear(); // clear the set s to allow new checks for each column   
            }

            // check each 3x3 box for duplicates
            for(int iBox = 0; iBox < 9; iBox + 3){
                for(int jBox = 0; jBox < 9; jBox + 3){
                    for(int i = iBox; i < iBox + 3; i++){
                        for(int j = jBox; j < jBox + 3; j++){
                            if(puzzleArray[i][j] != 0){
                                if(s.insert(!puzzleArray[i][j]).second){
                                    return 0;
                                }
                            }
                        }  
                    }
                    s.clear(); // clear the set s to allow new checks for each box
                }
            }
            return 1; 
        }

        // Function that accepts the puzzle array passed by reference and prints.
        void printPuzzle(int (&puzzleArray)[puzzleDim][puzzleDim]){
            for(int i = 0; i < puzzleDim; i++){
                for(int j = 0; j < puzzleDim; j++){
                    cout << puzzleArray[i][j] << " ";
                }  
                cout << "\n";
            }
        }         
};