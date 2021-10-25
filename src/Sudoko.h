#include <iostream>
#include <fstream>
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
            // if (choice == 'a'){
            //     acceptInput(numMatrix);
            // }
            // else{
            //     fileParse(numMatrix);
            // }
            //fileParse(numMatrix);
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
            }
            s.clear(); 
            // check each row for duplicates in that row
            for(int i = 0; i < puzzleDim; i++){
                for(int j = 0; j < puzzleDim; j++){
                    if(puzzleArray[i][j] != 0){
                        if(s.insert(puzzleArray[i][j]).second == false){
                            //cout << "The problem is with row duplicate. The value of matrix cell is: " << i << " " << j << ":  " << puzzleArray[i][j] << "\n";
                            return 0;
                        }
                    }    
                }
                s.clear(); // clear the set s to allow new checks for each row    
            }    
            s.clear(); 
            // check each column for duplicates in that column
            for(int i = 0; i < puzzleDim; i++){
                for(int j = 0; j < puzzleDim; j++){
                    if(puzzleArray[j][i] != 0){
                            if(s.insert(puzzleArray[j][i]).second == false){
                                //cout << "The problem is with column duplicate. The value of matrix cell is: " << j << " " << i << ":  " << puzzleArray[j][i] <<"\n";
                                return 0;
                            }
                        } 
                }
                s.clear(); // clear the set s to allow new checks for each column   
            }
            s.clear(); 
            // check each 3x3 box for duplicates
            for(int iBox = 0; iBox < 9; iBox += 3){
                for(int jBox = 0; jBox < 9; jBox += 3){
                    for(int i = iBox; i < iBox + 3; i++){
                        for(int j = jBox; j < jBox + 3; j++){
                            if(puzzleArray[i][j] != 0){
                                if(s.insert(puzzleArray[i][j]).second == false){
                                    //cout << "The problem is with box duplicate. The duplicate value is: " << i << " " << j << ":  " << puzzleArray[i][j] << "\n";
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

        // Function that parses tokens from file and populates numMatrix 
        int fileParse(int (&puzzleArray)[puzzleDim][puzzleDim]){
            int number;
            int i = 0;
            int j = 0;
            // File handling
            string filename("puzzle.txt");
            fstream input_file(filename);
            if (!input_file.is_open()){
                cerr << "Could not open the file - '"
                     << filename << "'" << endl;
                return EXIT_FAILURE;
            }
            // Load the puzzle array
            while (input_file >> number){
                puzzleArray[i][j] = number;
                if(j == (puzzleDim - 1)){
                    j = 0;
                    i++;
                }else{
                    j++;
                }

            }
            cout << endl;
            input_file.close();
            return EXIT_SUCCESS;
        }
};