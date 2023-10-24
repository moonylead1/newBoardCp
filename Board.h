#include <iostream>
#include <vector>
using namespace std;

int currentMove = 1;

class Board
{
private:
    /* data */
public:
    void boardShow(vector<vector<int>>);
    void boardMove();
    vector<vector<int>> boardGenerate(int, int);
    void boardSetup();
    int length;
    int width;
    int currentMove = 1;
    vector <vector <int>> board;

};

vector<vector<int>> Board::boardGenerate(int length, int width){
    vector<vector<int>> newBoard( width , vector<int> (length, 0));     // clear board with zero init
    return newBoard;
}

void Board::boardSetup(){ //make a new board for new game
  int task;
  cout << "1. (std9x9) 9x9 board;\n2. (std13x13) 13x13 board;\n3. (std19x19) 19x19 board\nEnter 1-3: ";
  cin >> task;
  switch (task) {
    case 1:
      Board::board = Board::boardGenerate(9, 9);
      Board::width = 9;
      Board::length = 9;
      break;
    case 2:
      Board::board = Board::boardGenerate(13, 13);
      Board::width = 13;
      Board::length = 13;
      break;
    case 3:
      Board::board = Board::boardGenerate(19, 19);
      Board::width = 19;
      Board::length = 19;
      break;
    default:
      cout << "Warning: no board was generated. Proceed? [Y] - yes, [N] - no : ";
      string afterCall;
      cin >> afterCall;
      if (afterCall == "n" or afterCall == "N"){
        break;
      }
  }
}

void Board::boardShow(vector<vector <int>> board){                           // show current board
  for (int width = 0; width < board.size(); width++){
    for (int length = 0; length < board.size(); length++){
      cout << board[width][length] << " ";
    }
    cout << endl;
  }
}

void Board::boardMove (){ //moves
  int x, y;
  Stone newStone;                                                   //idea to make a table where to write a save for a board with
  cout << "Enter coordinates x, y: ";                               //all stones inside, and make a recover for it
  cin >> x >> y;                                                    //also looking forward to make moves back and trees for them
  newStone.positionX = x-1;
  newStone.positionY = y-1;
  newStone.color = newStone.stoneColorSelect(currentMove);
  cout << "Current move: " << currentMove << endl;

  board[newStone.positionX][newStone.positionY] = newStone.color;
  currentMove++;

  boardShow(board);
}

