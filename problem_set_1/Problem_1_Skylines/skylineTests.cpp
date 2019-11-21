#include <iostream>
#include<stdlib.h>
#include "skyline.h"

int main(){
  vector<int> arr {93,84,33,64,62,83,63};
  node tree = buildingCartesianTree(arr);
  return 0;
}
