#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "Player.h"
using namespace std;
// you may change this enum as you need
enum class SquareType { Wall, Exit, Empty, Human, Enemy, Treasure, Trap};

// TODO: implement
// this function should return a string representation of a given SquareType
// for example an ascii letter or an emoji


class Board {
public:
	// TODO: implement
	Board();
	void PrintBoard();
	// already implemented in line
	int get_rows() const {return 4; }  // you should be able to change the size of your 
	int get_cols() const {return 4; }  // board by changing these numbers and the numbers in the arr_ field

//	// TODO: you MUST implement the following functions
	SquareType get_square_value(Position pos) const; 
//
//	// set the value of a square to the given SquareType
	void SetSquareValue(Position pos, SquareType value);
//
//	// get the possible Positions that a Player could move to
//	// (not off the board or into a wall)
	vector<Position> GetMoves(Player *p);
//
//	// Move a player to a new position on the board. Return
//	// true if they moved successfully, false otherwise.
	bool MovePlayer(Player *p, Position pos);
	void MoveComputer();
//	// Get the square type of the exit square
	SquareType GetExitOccupant();
//
//	// You probably want to implement this
	friend ostream& operator<<(ostream& os, const Board &b);

private:
	SquareType arr_[4][4];
	
	int rows_; // might be convenient but not necessary
	int cols_;
	
	// you may add more fields, as needed
};  // class Board

class Maze {
	public:
//	// TODO: implement these functions
		Maze(); // constructor
		Board GetBoard(){return *board_; }
//	// initialize a new game, given one human player and 
//	// a number of enemies to generate
		void NewGame(Player *human, const int enemies);
//
//	// have the given Player take their turn
		void TakeTurn(Player *p);
//
//	// Get the next player in turn order
		Player * GetNextPlayer();
//
//	// return true iff the human made it to the exit 
//	// or the enemies ate all the humans
		bool IsGameOver();

		int IncrementTurn(){return turn_count_++; }
//	// You probably want to implement these functions as well
//	// string info about the game's conditions after it is over
		string GenerateReport();
		friend ostream& operator<<(ostream& os, const Maze &m);
//
	private:
		Board *board_; // HINT: when you instantiate your board_, use the new Board() syntax
		vector<Player *> players_;
		int turn_count_;
//
//	// you may add more fields, as needed
//
};  // class Maze

#endif  // MAZE_H
