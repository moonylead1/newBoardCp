#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;

vector <vector <int>> board; // init of a board
string command = ""; // string for command;
int currentMove = 1; // first move by default is black

void boardShow(vector<vector <int>> board){                           // show current board
  for (int width = 0; width < board.size(); width++){
    for (int length = 0; length < board.size(); length++){
      cout << board[width][length] << " ";
    }
    cout << endl;
  }
}

int stoneColorSelect(){
  if (currentMove % 2 == 0){
    return 2;
  }
  return 1;
}

vector <vector <int>> boardGenarate(int length, int width){           // generate board
  vector<vector<int>> newBoard( length , vector<int> (width, 0));     // clear board with zero init
  return newBoard;
}


void boardSetup(){ //make a new board for new game
  int task;
  cout << "1. (std9x9) 9x9 board;\n2. (std13x13) 13x13 board;\n3. (std19x19) 19x19 board\nEnter 1-3: ";
  cin >> task;
  switch (task) {
    case 1:
      board = boardGenarate(9, 9);
      break;
    case 2:
      board = boardGenarate(13, 13);
      break;
    case 3:
      board = boardGenarate(19, 19);
    default:
      cout << "Warning: no board was generated. Proceed? [Y] - yes, [N] - no : ";
      string afterCall;
      cin >> afterCall;
      if (afterCall == "n" or afterCall == "N"){
        break;
      }
  }
}

void boardMove (){ //moves
  int x, y;
  cout << "Enter coordinates x, y: ";
  cin >> x >> y;
  board[x-1][y-1] = stoneColorSelect();
  currentMove++;
  cout << "Current move: " << currentMove-1 << endl;
  boardShow(board);
}
void commandQuit(){
  cout << "Quit command requested. Proceed? [Y] - yes, [N] - no : ";
  string afterCall;
  cin >> afterCall;
  if (afterCall == "Y" or afterCall == "y"){
    exit(1);
  }
}
void commandList(string command) { //command list executable;
  if (command == "open new" or command == "on"){
    boardSetup();
  }
  if (command == "move" or command == "m"){
    boardMove();
  }
  if (command=="quit" or command == "q"){
    commandQuit();
  }
  //...
}

int main (int argc, char *argv[]) {
  while (true) {
    cout << "cmd line: ";
    cin >> command;
    commandList(command); //excecutes command from list of avaible
  }
  return 0;
}
