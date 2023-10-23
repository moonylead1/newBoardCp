#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector <vector <int>> board;
string command = ""; // string for command;
                     //
int currentMove = 1;

int stoneColorSelect(){
  if (currentMove % 2 == 0){
    return 2;
  }
  return 1;
}
vector <vector <int>> generateBoard(int length, int width){
  vector<vector<int>> newBoard( length , vector<int> (width, 0));
  return newBoard;
}


void boardSetup(){ //make a new board for new game
  int task;
  cout << "1. (std9x9) 9x9 board;\n2. (std13x13) 13x13 board;\n3. (std19x19) 19x19 board\nEnter 1-3: ";
  cin >> task;
  switch (task) {
    case 1:
      board = generateBoard(9, 9);
      break;
    case 2:
      board = generateBoard(13, 13);
      break;
    case 3:
      board = generateBoard(19, 19);
    default:
      
      break;
  }
} 


void boardMove (){ //moves
  int x, y;
  cout << "Enter coordinates x, y: ";
  cin >> x >> y;
  board[x][y] = stoneColorSelect();
  currentMove++;
}

void commandList(string command) { //command list executable;
  if (command == "open new" or command == "on"){
    boardSetup();
  }
  if (command == "move" or command == "m"){
    boardMove();
  }
  //...
}

int main (int argc, char *argv[]) {  
  while (true) {
    cin >> command;
    if (command==""){
      cout << "no command was written";
      break;
    }
    commandList(command);
  }
  return 0;
}
