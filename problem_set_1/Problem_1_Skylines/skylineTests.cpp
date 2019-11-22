#include <iostream>
#include<stdlib.h>
#include "skyline.h"

int main(){
  vector<int> arr {93,84,33,64,62,83,63,12,24};
  node tree = buildingCartesianTree(arr);
  printTreePositions(&tree);

  return 0;
}
