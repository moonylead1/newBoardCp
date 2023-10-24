#include <iostream>
using namespace std;

class Stone{
    public:
        int positionX, positionY;
        int color;
        int stoneColorSelect(int);                       //1 - for black; 2 - for white;
};

int Stone::stoneColorSelect(int currentMove){
  if (currentMove % 2 == 0){
    return 2;
  }
  return 1;
}
