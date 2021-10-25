#include <iostream>
#include <string>
#include "Sudoko.h"

using namespace std;

int main()
{
    string choice;                                            // string indicating user's choice
    cout << "Justin's Sudoku Puzzle Program" << "\n\n";
    while (true)
    {
        cout << "Enter \"keyboard\" to input a Sudoko puzzle from the keyboard" << "\n"
                "Enter \"file\" to input a Sudoko puzzle from a file" << "\n"
                "Enter \"exit\" to exit the program" << "\n\n";

        cin >> choice;
        if(choice == "keyboard"){
            puzzle newPuzzle(choice);                       // create a puzzle object from input
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