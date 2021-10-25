#include <iostream>
#include <fstream>
#include <string>
#include "Sudoko.h"
using namespace std;

int main()
{
    ofstream inputFile;
    string choice;                                            // string indicating user's choice
    string saveToFile;
    cout << "Justin's Sudoku Puzzle Program" << "\n\n";
    while (true)
    {
        cout << "Enter \"keyboard\" to input a Sudoko puzzle from the keyboard" << "\n"
                "Enter \"file\" to input a Sudoko puzzle from a file" << "\n"
                "Enter \"exit\" to exit the program" << "\n\n";

        cin >> choice;
        if(choice == "keyboard"){
            puzzle newPuzzle(choice);                       // create a puzzle object from input
            if (newPuzzle.validity > 0){
                cout << "\nEnter \"save\" to save your puzzle to a file. "
                        "Otherwise, enter anything else to continue:\n";
                cin >> saveToFile;
                cout << "\n";
                if (saveToFile == "save"){
                    newPuzzle.fileSave(newPuzzle.numMatrix, inputFile);
                }
            }
        } else if (choice == "file"){
            puzzle newPuzzle(choice);                       // create a puzzle object from file    
        } else if (choice == "exit"){
            cout << "Exiting...\n";
            break;
        } else{
            cout << "Invalid input. Try again\n\n";
            continue;
        }
    }
    return 0;
}