//  C++ Program:    Lab3.cpp
//  Course:         CSE 1311 / W01
//  Name:           Austin Pettit
//  Assignment:     Lab 3
//  Due Date:       6/17/18

/*  Purpose:
 *  This program is a Rock-Paper-Scissors game. The user makes a selection
 *  and the program will randomly generate it's move and a winner will be
 *  determined by the Rock Paper Scissors rules.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    // declare vars
    int compNumResp;   // numerical values corresponding to comp selection
    int userScore = 0, compScore = 0;    // stores score values
    char userResp, compResp;        // char values corresponding to user/comp choices
    bool menuLoop = true, keepPlaying;  // controls menu & game looping

    // initialize random seed
    srand(time(0));

    // handles the game menu
    while(menuLoop){

        cout << "\n=================================" << endl;
        cout << "Welcome to Rock Paper Scissors!" << endl;
        cout << "       by Austin Pettit" << endl;
        cout << "=================================" << endl;
        cout << "To play, enter 'p' or to quit, enter 'x' >>  ";
        cin >> userResp;

        // evaluate user response
        switch(userResp){
            case 'p':
                cout << "\nGet ready! THE GAME IS STARTING... " << endl;
                keepPlaying = true;
                menuLoop = false;
                break;
            case 'x':
                menuLoop = false;
                break;
            default:
                cout << "\nInvalid selection. Please try again." << endl;
                break;
        }
    }

    // game loops until user quits
    while(keepPlaying){
        // generate comp selection
        compNumResp = rand() % 3;

        // assign alpha value for comp's integer selection
        switch(compNumResp){
            case 0:
                // rock
                compResp = 'r';
                break;
            case 1:
                // paper
                compResp = 'p';
                break;
            case  2:
                // scissors
                compResp = 's';
                break;

        }

        //ask user for input
        cout << "\n========== YOU: " << userScore << "    COMPUTER: " << compScore << " ==========" << endl;
        cout << "Your turn! Choose (r) for Rock, (p) for Paper, or (s) for Scissors. To quit, enter (x)." << endl;
        cout << "Your selection >> ";
        cin >> userResp;

        if(userResp == 'x'){
            // user wants to exit
            keepPlaying = false;
            cout << "\nGoodbye!" << endl;
        } else if(userResp == compResp ){
            // user and computer had same letter
            cout << "\nGreat minds think alike - there was a tie! Make another selection." << endl;
        } else {
             // user and computer differ - check each combination
            if(userResp == 'r' && compResp == 'p'){
                cout << "\nPaper covers rock! You lost." << endl;
                compScore++;
            } else if (userResp == 'r' && compResp == 's'){
                cout << "\nRock smashes scissors! You won!" << endl;
                userScore++;
            } else if (userResp == 'p' && compResp == 'r'){
                cout << "\nPaper covers rock! You won!" << endl;
                userScore++;
            } else if (userResp == 'p' && compResp == 's'){
                cout << "\nScissors cut paper! You lost." << endl;
                compScore++;
            } else if (userResp == 's' && compResp == 'r'){
                cout << "\nRock smashes scissors! You lost." << endl;
                compScore++;
            } else if (userResp == 's' && compResp == 'p'){
                cout << "\nScissors cut paper! You won!" << endl;
                userScore++;
            } else {
                cout << "\nYou've entered an invalid option! Please enter one of the letters in the parenthesis." << endl;
            }
        }
    }

    cout << "\nCreated by Austin Pettit" << endl;
    return 0;
}