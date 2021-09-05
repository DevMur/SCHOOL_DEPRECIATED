#include "Player.h"

//players start in the same spot everytime the only change is in their name
Player::Player(const string name, const bool is_human)
{
    name_ = name;
    points_ = 0;
    pos_.row = 0;
    pos_.col = 0;
    is_human_ = is_human;
}
//points start at 0 and are summed by each treasure
void Player::ChangePoints(const int x)
{
    points_ += x;
}
//row and col set for redundency sake
void Player::SetPosition(Position pos)
{
    pos_.row = pos.row;
    pos_.col = pos.col;
}
//unused but implemented
string Player::ToRelativePosition(Position other)
{
    if (pos_.row == other.row && pos_.col > other.col){
        return "down";
    }
    else if (pos_.row == other.row && pos_.col < other.col){
        return "up";
    }
    else if (pos_.row > other.row && pos_.col == other.col){
        return "left";
    }
    else{
        return "right";
    }
}
//also unused when the member variables can be accessed and are easier to deal with
//rather than parsing and formatting for an endgame report
string Player::Stringify()
{
    string strname = name_;
    string strpoints = to_string(points_);
    string stringrow = to_string(pos_.row);
    string stringcol = to_string(pos_.col);
    string humanity;
    if (is_human_){humanity = "t";}
    else{humanity = "f";}
    return strname + " " + strpoints + " " + stringrow + " " + stringcol + " " + humanity;
}
