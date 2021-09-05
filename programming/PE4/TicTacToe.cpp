#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//Devins version
void DisplayBoard(vector<vector<int>> &current_board) //takes the current board as input
{
    for (int i = 0; i < 3; i++) //3's are faster than vector.size() calls. It'll always be 3
    {
        for (int j = 0; j < 3; j++)
        {
            cout << current_board[i][j] << " "; //prints the row, no endl
        }
        cout << endl; //once a row exits an endl is used
    }
}

int GetPlayerChoice()
{
    int choice;
    cout << "Enter your choice, 1-9: ";
    cin >> choice;
    if (!(choice > 9 || choice < 1))
    {
        return choice;
    }
    else
    {
        cout << "Invalid input!" << endl;
        return -1;
    }
}

void PlaceMarker(int location, int XO, vector<vector<int>> &current_board)
{
    if (location <=3)
    {
        current_board[0][location-1] = XO;
    }
    else if (location > 3 && location <= 6)
    {
        current_board[1][location-4] = XO;
    }
    else
    {
        current_board[2][location-7] = XO;
    }
    cout << "PLACED" << endl;
}


//Fill the board with 0's, 1's can be X's and 2's can be O's
//-1 as a return or at a location can denote failure.
//there are only three keys to display.
vector<vector<int>> createBoard()
{
    vector<vector<int>> our_board; //solution
    vector<int> row_array; //values in a row
    for (int i = 0; i < 3; i++) //col#
    {
        for (int j = 0; j < 3; j++) //row element
        {
            row_array.push_back(0); //populate all columns with 0's
        }
        our_board.push_back(row_array); //populate the row
        row_array.clear(); //clear the old vector for the next rows elements
    }
    return our_board;
}

void Rules()
{
    cout << "Player 1 is X" << endl;
    cout << "Player 2 is O" << endl;
    int counter = 1;
    for (int i = 1; i <= 3; i++) //col#
    {
        for (int j = 1; j <= 3; j++) //row element
        {
            cout << counter++ << " ";
        }
        cout << endl;
    }
    cout << "Place your move by entering the location, 1-9" << endl;
}

int main()
{
    //a tictactoe board does not require anything too creative. It is a 3x3 matrix
    //nothing more, nothing less.
    vector<vector<int>> board = createBoard();
    int move;
    int turn_count = 0;
    int XorO = 1;
    Rules();
    //board[1][1] = 8; //used to test memory
    
    while (turn_count < 9)
    {
        if (turn_count % 2 == 0)
        {
            XorO = 1;
            move = GetPlayerChoice();
            PlaceMarker(move, XorO, board);
            DisplayBoard(board);
        }
        else
        {
            XorO = 2;
            move = GetPlayerChoice();
            PlaceMarker(move, XorO, board);
            DisplayBoard(board);
        }
        turn_count++;
    }
    //DisplayBoard(board); 
}