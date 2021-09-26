#include <iostream>
#include <vector>
#include "Sudoko.h"

using namespace std;

int main()
{
    char choice;                        // character indicating the user's choice to end the program
    vector<puzzle> vectorOfPuzzles;     // vector of Sudoko puzzles.

    cout << "Justin's Sudoku Puzzle Program" << "\n\n";

    while (true)
    {
        cout << "Enter \"a\" to input a Sudoko puzzle from the keyboard" << "\n"
                "Enter \"b\" to exit the program" << "\n\n";
        /*puzzle newPuzzle('c');        // debugging
        cout << "Validity is: " << newPuzzle.validity << "\n\n"; 
        break;*/
        cin >> choice;
        if(choice == 'a'){
            puzzle newPuzzle;                       // create a puzzle object
            
            if(newPuzzle.validity < 1){
                cout << "Invalid puzzle\n";
                cout << "Validity variable is " << newPuzzle.validity << "\n";
            }else{
                newPuzzle.printPuzzle(newPuzzle.numMatrix);
            }
            
            vectorOfPuzzles.push_back(newPuzzle);   // adds and stores new puzzle object
        } else if (choice == 'b'){
            cout << "Exiting...\n";
            break;
        } else{
            cout << "Invalid input. Try again\n\n";
            continue;
        }
    }
    return 0;
}