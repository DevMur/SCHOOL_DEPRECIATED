#include "Maze.h"
#include "Player.h"
//boiler plate function asked to be implemented, unused
string SquareTypeStringify(SquareType sq)
{
	if (sq == SquareType::Wall){return "wall";}
	else if (sq == SquareType::Exit){return "exit";}
	else if (sq == SquareType::Empty){return "empty";}
	else if (sq == SquareType::Human){return "human";}
	else if (sq == SquareType::Enemy){return "enemy";}
	else {return "treasure";}
}

int main()
{
//used for different seeds/values of rand()
    srand(time(NULL)); 

//game start info
    cout << "There is one computer trying to kill you." << endl;
    cout << "There is also a hidden pitfall." << endl;
    cout << "You have a 15 move limit, if you exceed it you wil die..." << endl;


//initialize a player with username
    cout << "Enter Username: ";
    string pname;
    cin >> pname;
    Player *one = new Player(pname, true);

//create a board and maze overlay for this board
    Maze overlay;
    overlay.NewGame(one, 2);
    bool gg = false;

//play the game while the game is over (?) condition is false
    while (gg == false)
    {
        overlay.GetBoard().PrintBoard(); //print the current board
        overlay.TakeTurn(one);
        gg = overlay.IsGameOver();
    }
    if (overlay.IncrementTurn()-1 < 15)
    {
        one->ChangePoints(1);
    }
    string not_needed = overlay.GenerateReport();
    return 0;
}