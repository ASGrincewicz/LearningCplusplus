#include <iostream>
#include "ctime"
#include "cstdlib"
using namespace std;

const int MAX_CHIPS = 100;
const float MAX_TURN = 0.5;

string FindPlayerName(string names[], bool playerTurn);

int main()
{
    bool player1Turn = true;
    bool gameOver = false;
    int chipsInPile = 0;
    int chipsTaken = 0;
    int maxPerTurn = 0;
    string playerName[2];
    char userChoice;
    //seed the random number generator.
    srand(time(0));

    cout << "Player One please enter your name:\n";
    cin>> playerName[0];
    cout << "Welcome, " << playerName[0]<< "!" << endl;

    cout << "Player Two please enter your name: \n";
    cin >> playerName[1];
    cout << "Welcome, " << playerName[1]<<"!" << endl;
    cout << "It will be " << playerName[0] <<" VS "<< playerName[1]<< endl;

    do
    {
        chipsInPile = (rand() % MAX_CHIPS) + 1;
        cout << "This round will start with " << chipsInPile << " chips in the pile\n";
        gameOver = false;
        while (!gameOver)
        {
            do
            {
                cout <<FindPlayerName(playerName, player1Turn) << ", How many chips would you like?\n";
                maxPerTurn = (MAX_TURN * chipsInPile);
                cout << "You can only take up to ";
                if (maxPerTurn == 0)
                    cout << "1\n";
                else
                    cout << maxPerTurn << endl;

                cin >> chipsTaken;
            }
            while (chipsTaken > (maxPerTurn) && chipsInPile > 1);
            chipsInPile = chipsInPile - chipsTaken;
            cout << "There are " << chipsInPile << " left in the pile\n";
            if (chipsInPile == 0)
            {
                gameOver = true;
                cout <<FindPlayerName(playerName, player1Turn) << " , wins!\n";
            }
            else
                player1Turn = !player1Turn;
        }
        cout << "Do you want to play again? (Y/N)\n";
        cin >> userChoice;
    }
    while((userChoice == 'y') || (userChoice =='Y'));
    return 0;
}
string FindPlayerName(string names[], bool playerTurn)
{
    if(playerTurn ==true)
        return names[0];
    else
        return names[1];
}