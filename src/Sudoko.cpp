#include <iostream>
#include "Sudoko.h"

using namespace std;

int main()
{
    bool done = false;
    char choice;

    cout << "Justin's Sudoku Puzzle Program" << "\n\n";

    while (!done)
    {
        cout << "Enter \"a\" to input a Sudoko puzzle from the keyboard" << "n"
                "Enter \"b\" to exit the program" << "\n\n";

        cin >> choice;

        if(choice == 'a'){
            puzzle puzzle1;
        } else {
            break;
        }

    }
    
    return 0;
}