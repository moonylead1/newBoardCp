#include <iostream>
using namespace std;

class Board
{
private:
    /* data */
public:
    vector<vector<int>> boardGenerate(int, int);
    void boardSetup();
    int length;
    int width;
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
      break;
    case 2:
      Board::board = Board::boardGenerate(13, 13);
      break;
    case 3:
      Board::board = Board::boardGenerate(19, 19);
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
