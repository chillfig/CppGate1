#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <set>
#include <string>
const int puzzleDim = 9;    // [puzzleDim x puzzleDim] puzzle dimension

using namespace std;

class puzzle{
    public:
        int numMatrix[puzzleDim][puzzleDim];    // puzzle matrix
        int fileStat = 0;                       // 0 if filestream is valid, 1 if error
        int validity;                           // -1 if the puzzle contains an invalid value 
                                                // 0 if the puzzle contains repeated values
                                                // 1 if the puzzle is valid
        string saveToFile;                      // "save" if user wants to save their input

        puzzle(string choice){   // constructor that executes at object creation
            // capture puzzle from user
            if (choice == "keyboard"){
                acceptInput(numMatrix);
            }
            else if(choice == "file"){
                fileStat = fileParse(numMatrix);
            }
         
            // communicate validity of puzzle to user 
            if (fileStat == 0){
                validity = validatePuzzle(numMatrix);
                switch (validity){
                case 1:
                    printPuzzle(numMatrix);
                    // If keyboard-entered puzzle, then give option to save
                    if (choice == "keyboard"){
                        cout << "\nEnter \"save\" to save your puzzle to a file. "
                        "Otherwise, enter anything else to continue:\n";
                        cin >> saveToFile;
                        cout << "\n";
                        if (saveToFile == "save"){
                            fileSave(numMatrix);
                        }
                    }
                    // Attempt to solve the valid puzzle
                    if (solvePuzzle(numMatrix, 0, 0)){
                        cout << "\nThe solved puzzle is:\n";
                        printPuzzle(numMatrix);
                    }else{
                        cout << "The given puzzle can't be solved\n\n";
                    }
                    break;
                case 0:
                    cout << "The given puzzle contains repeated values\n\n";
                    break;
                case -1:
                    cout << "The given puzzle contains an invalid value\n\n";
                    break;    
                default:
                    cout << "Error\n";
                    break;
                }
            }
        }
        ~puzzle(){  // destructor to prevent memory leaks
            cout << "\n\nPuzzle object destroyed. Memory leak prevented\n\n";
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
            for(int iBox = 0; iBox < puzzleDim; iBox += 3){
                for(int jBox = 0; jBox < puzzleDim; jBox += 3){
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
            string filename;
            int number;
            int i = 0;
            int j = 0;
            // Obtain file name from user
            cout << "Enter the filename: ";
            cin >> filename;
            
            // File handling
            fstream input_file(filename);
            if (!input_file.is_open()){
                cerr << "Could not open the file - '"
                     << filename << "'\n" << endl;
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

        // Function that saves puzzle to file
        void fileSave(int (&puzzleArray)[puzzleDim][puzzleDim]){
            string filename;
            ofstream output_file;

            // Obtain file name from user
            cout << "Enter the filename to save to: ";
            cin >> filename;

            // Store the puzzle array
            output_file.open(filename.append(".txt"));
            for (int i = 0; i < puzzleDim; i++){
                for (int j = 0; j < puzzleDim; j++){
                    output_file << puzzleArray[i][j] << " ";
                }
                output_file << "\n";
            }
            output_file.close();
        }

        // Function that solves the puzzle
        bool solvePuzzle(int (&puzzleArray)[puzzleDim][puzzleDim], int row, int col){
            // If we are indexed at the end, return true, no more backtracking needed
            if (row == puzzleDim - 1 && col == puzzleDim){
                return true;
            }
            // If we are indexed at the end of a row, then increment row, restart col
            if (col == puzzleDim){
                row++;
                col = 0;
            }
            // if nonzero element at index, recursively solve with next element. No need to fill
            if (puzzleArray[row][col] > 0) {
                return solvePuzzle(puzzleArray, row, col + 1);
            }
            for (int num = 1; num <= 9; num++){
                puzzleArray[row][col] = num;
                // check if current guess, passess validation
                if (validatePuzzle(puzzleArray))
                {
                    // use the guess at curent element and recursively solve with next element
                    if (solvePuzzle(puzzleArray, row, col + 1))
                        return true;
                }
                // our guess is wrong, reset value at current index to 0 and try new value
                puzzleArray[row][col] = 0;
            }
            // back track if nothing works
            return false;
        }
};