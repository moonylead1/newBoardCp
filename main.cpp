#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>

#include "Stone.h"
#include "Board.h"
#include "Command.h"
using namespace std;

Board newBoard;
vector <vector <int>> board; // init of a board
string command = ""; // string for command;

void commandQuit(){
  cout << "Quit command requested. Proceed? [Y] - yes, [N] - no : ";
  string afterCall;
  cin >> afterCall;
  if (afterCall == "Y" or afterCall == "y"){
    exit(1);
  }
}

void commandList(string command) { //command list executable; //later need an upd to write an class with it to not get oaver load on the main code

  if (command == "startup" or command == "su"){
    newBoard.boardSetup();
  }

  if (command == "move" or command == "m"){
    newBoard.boardMove();
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


