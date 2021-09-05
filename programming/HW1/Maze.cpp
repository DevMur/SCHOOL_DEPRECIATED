#include "Maze.h"
//#include "Player.cpp"


//make an empty board, it doesn't have any overlay 
//but changing the loop size would change the board dimensions
Board::Board()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr_[i][j] = SquareType::Empty;
        }
    }
    rows_ = 4;
    cols_ = 4;
}

//horizontally then vertically, stringify could be used to decrease if statement redundencies 
//pretty straight forward print an output depending on the current iteration of the squaretype
void Board::PrintBoard()
{
    Position use;
    for (int i = 0; i < 4; i++)
    {
        use.row = i;
        for (int j = 0;j < 4; j++)
        {
            use.col = j;
            if ((*this).get_square_value(use)==SquareType::Empty)
            {
                cout << " 0 ";
            }
            else if ((*this).get_square_value(use)==SquareType::Wall)
            {
                cout << " X ";
            }
            else if ((*this).get_square_value(use)==SquareType::Human)
            {
                cout << " :) ";
            }
            else if ((*this).get_square_value(use)==SquareType::Enemy)
            {
                cout << " <|> ";
            }
            else if ((*this).get_square_value(use)==SquareType::Treasure)
            {
                cout << " t ";
            }
            else if ((*this).get_square_value(use)==SquareType::Exit)
            {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

//given (x,y) coordinates return the squarevalue enum
SquareType Board::get_square_value(Position pos) const{ return arr_[pos.row][pos.col]; }


//given (x,y) and the new squarevalue, set it to be so.
void Board::SetSquareValue(Position pos, SquareType value)
{
    arr_[pos.row][pos.col] = value;
}

//given the current player check all 4 directions, depending on walls, enemies, exits, etc
//return the directions that are allowed in the form of a vector of positions
vector<Position> Board::GetMoves(Player *p)
{
    //variables used
    vector<Position> solution;
    Position tmp = p->get_position();
    bool up = true, down = true, left = true, right = true;
    
    //base case of walls
    if(tmp.row == 0){up = false; }
    else if (tmp.row == 3){down = false; }
    if(tmp.col == 0){left = false; }
    else if (tmp.col == 3){right = false; }

    //if the base cases are still true check that the position isnt already occupied
    if (up == true)
    {
        tmp.row--;
        SquareType upkey = get_square_value(tmp);
        if (upkey == SquareType::Empty || upkey == SquareType::Treasure){solution.push_back(tmp);}
        tmp.row++;
    }
    if (down == true)
    {
        tmp.row++;
        SquareType downkey = get_square_value(tmp);
        if (downkey == SquareType::Empty || downkey == SquareType::Treasure || downkey == SquareType::Exit){solution.push_back(tmp);}
        tmp.row--;
    }
    if (left == true)
    {
        tmp.col--;
        SquareType leftkey = get_square_value(tmp);
        if (leftkey == SquareType::Empty || leftkey == SquareType::Treasure){solution.push_back(tmp);}
        tmp.col++;
    }
    if (right == true)
    {
        tmp.col++;
        SquareType rightkey = get_square_value(tmp);
        if (rightkey == SquareType::Empty || rightkey == SquareType::Treasure || rightkey == SquareType::Exit){solution.push_back(tmp);}
        tmp.col--;
    }

    return solution;
}

//use the allowed moves to change the location of the player
bool Board::MovePlayer(Player *p, Position pos)
{
    vector<Position> allowed = GetMoves(p);

    for (int i = 0; i < allowed.size(); i++)
    {
        if (pos.row == allowed[i].row && pos.col == allowed[i].col)
        {
            //this point addition could be moved to another function, especially if 
            //multiple treasures or moving traps are used
            if (get_square_value(pos) == SquareType::Treasure)
            {
                p->ChangePoints(100);
            }
            p->SetPosition(pos);
            return true;
        }
    }
    //if the move is not allowed
    return false;
}

//Blinky style chase depending on human location
//cannot move onto the human square as a 4x4 is too small to ever beat the computer
void Board::MoveComputer()
{
    Position computer_current;
    Position player_current;
    SquareType looking_at;

//find the computer and human
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr_[i][j] == SquareType::Enemy)
            {
                computer_current.col = j;
                computer_current.row = i;
            }
            if (arr_[i][j] == SquareType::Human)
            {
                player_current.col = j;
                player_current.row = i;
            }
        }
    }

//depending on the location of the computer relative to the human move the greater distance
//if the human is 3 above but in the same column then move up, if 3 left but on the same row move left, etc.
    if ((computer_current.col - player_current.col) > (computer_current.row - player_current.row))
    {
        computer_current.col--;
        looking_at = (*this).get_square_value(computer_current);
        if (looking_at == SquareType::Human)
        {
            cout << "Game over sequence" << endl;
        }
        else if (looking_at == SquareType::Empty)
        {
            (*this).SetSquareValue(computer_current, SquareType::Enemy);
            computer_current.col++;
            (*this).SetSquareValue(computer_current, SquareType::Empty);
            return;
        }
        else{return; }
    }
    else if ((computer_current.col - player_current.col) < (computer_current.row - player_current.row))
    {
        computer_current.row--;
        looking_at = (*this).get_square_value(computer_current);
        if (looking_at == SquareType::Human)
        {
            cout << "Game over sequence" << endl;
        }
        else if (looking_at == SquareType::Empty)
        {
            (*this).SetSquareValue(computer_current, SquareType::Enemy);
            computer_current.row++;
            (*this).SetSquareValue(computer_current, SquareType::Empty);
            return;
        }
        else{return; }
    }
    else if ((computer_current.col - player_current.col) < 0 || ((computer_current.row - player_current.row) < 0 && (computer_current.col - player_current.col) > (computer_current.row - player_current.row)))
    {
        computer_current.row++;
        looking_at = (*this).get_square_value(computer_current);
        if (looking_at == SquareType::Human)
        {
            cout << "The Computer Killed you!" << endl;
            Position endgame;
            endgame.col = 3;
            endgame.row = 3;
            SetSquareValue(endgame, SquareType::Human);
        }
        else if (looking_at == SquareType::Empty)
        {
            (*this).SetSquareValue(computer_current, SquareType::Enemy);
            computer_current.row--;
            (*this).SetSquareValue(computer_current, SquareType::Empty);
            return;
        }
        else{return; }
    }
    else
    {
        computer_current.col++;
        looking_at = (*this).get_square_value(computer_current);
        if (looking_at == SquareType::Human)
        {
            cout << "Game over sequence" << endl;
        }
        else if (looking_at == SquareType::Empty)
        {
            (*this).SetSquareValue(computer_current, SquareType::Enemy);
            computer_current.col--;
            (*this).SetSquareValue(computer_current, SquareType::Empty);
            return;
        }
        else{return; }
    }
}

//not sure why this is needed when the grid size is mandatory and the exit location is always known
SquareType Board::GetExitOccupant(){return SquareType::Exit; }


//initialize the board to be overlayed and set the turn count to 0
Maze::Maze()
{
    board_ = new Board();
    turn_count_ = 0;
}

//create the overlay for the board, walls, humans, traps, computers, treasure
void Maze::NewGame(Player *human, const int enemies)
{
    Position abuse;
    int squaretype;

    for (int i = 0; i < 4; i++)
    {
        for(int k = 0; k < 4; k++)
        {
            squaretype = rand() % 100; //the srand in main is so rand of 100 can be used

//since Walls get the first dibs at a square it is if else statements based on a number 0-99
            if (squaretype < 20)
            {
                abuse.row = i;
                abuse.col = k;
                board_->SetSquareValue(abuse, SquareType::Wall);
            }
            else if (20 <= squaretype && squaretype < 30)
            {
                abuse.row = i;
                abuse.col = k;
                board_->SetSquareValue(abuse, SquareType::Treasure);
            }
            else //redundent but keeps with the workflow
            {
                abuse.row = i;
                abuse.col = k;
                board_->SetSquareValue(abuse, SquareType::Empty);
            }
         }
     }
//player[0]
     players_.push_back(human);

//these are known locations, can be hardcoded 
     abuse.row = 0;
     abuse.col = 0;
     board_->SetSquareValue(abuse, SquareType::Human);
     abuse.row = 3;
     abuse.col = 2;
     board_->SetSquareValue(abuse, SquareType::Enemy);
     abuse.row = 2;
     abuse.col = 3;
     //board_->SetSquareValue(abuse, SquareType::Enemy);
     abuse.row = 3;
     abuse.col = 3;
     board_->SetSquareValue(abuse, SquareType::Exit);
}

//use the user input and rules defined by the move function to move a player
//once the player has moved or failed to move the computer gets a turn
void Maze::TakeTurn(Player *p)
{
    Position desired_move = p->get_position();
    Position oldLocation = p->get_position();

//wasd is much more satisfying than typing out a full direction although its an easy change
    cout << "Enter a direction to move (w, a, s, d): ";
    string move;
    cin >> move;
    
    //the desired move can only by one member variable changing by one.
    if (move == "w"){desired_move.row--;}
    else if (move == "s"){desired_move.row++;}
    else if (move == "a"){desired_move.col--;}
    else{desired_move.col++;}

//if the player gets moved the old location is changed to empty (important if prev was treasure)
    bool did_move = board_->MovePlayer(p, desired_move);
    if (did_move)
    {
        board_->SetSquareValue(oldLocation, SquareType::Empty);
        board_->SetSquareValue(desired_move, SquareType::Human);
    }
    else{cout << "failed to move" << endl;}
    
    board_->MoveComputer();
}

//Implemented a turn limit and a trap
bool Maze::IsGameOver()
{
    Position endpoint;
    endpoint.col = 3;
    endpoint.row = 3;
    Position trap = endpoint;
    trap.row -= 2;
//since the computer is more like a moving wall since it's OP the trap is the only trip for a game over
    if ((*board_).get_square_value(endpoint) == SquareType::Human || IncrementTurn() > 15 || (*board_).get_square_value(trap) == SquareType::Human)
    {
        if ((*board_).get_square_value(trap) == SquareType::Human)
        {
            cout << "You died by trap, remember where it is for next time!" << endl;
        }
        return true;
    }
    return false;
}

//call known info once the IsGameOver() returns true
string Maze::GenerateReport()
{
    cout << "Game Over" << endl;
    cout << "Moves: " << IncrementTurn()-1 << endl;
    cout << "Score: " << (*players_[0]).get_points() << endl;
    return "Done";
}