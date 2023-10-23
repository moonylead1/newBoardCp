include <iostream>
include <math.h>
using namespace std;

string command = ""; // string for command;
void boardMove (){
  int x, y;
  cout << "Enter coordinates x, y: "
  cin >> x >> y;

}

void commandList() { //command list executable;
  if (command == "move"){
    boardMove();
  }
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
