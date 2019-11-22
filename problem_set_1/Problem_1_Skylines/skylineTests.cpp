#include <iostream>
#include<stdlib.h>
#include "skyline.h"

int main(){
  //vector<int> arr {93,84,33,64,62,83,63,12,24,36,37,38};
  //node tree = buildingCartesianTree(arr);
  //printTreePositions(&tree);

  //cout << findArea(2,6,&tree) << " \n";
  //cout << findNumberOfChildren(&tree) << " \n";


  //vector<int> arr{2,7,1,8,3,0,5,4};
  //node tree = buildingCartesianTree(arr);

  //printTree(&tree);

  vector<int> arr {1,3,7,4,2};
  node tree = buildingCartesianTree(arr);
  cout << calculateMaximumSkylineArea(&tree) << " \n";
  return 0;
}
