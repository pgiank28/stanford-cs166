#include <bits/stdc++.h>
using namespace std;

struct nodes{
  int value;
  int position;
  nodes* leftChild;
  nodes* rightChild;
};


typedef struct nodes* node;

int calculateMaximumSkylineArea(node* cartessianTree);
int findNumberOfChildren(node* cartessianTree);
int findArea(int x,int y,node* cartessianTree);
node buildingCartesianTree(vector<int> array);
int findMinimumValue(int leftPos,int rightPos);
void expandTree(node* tree,node n);
void printTree(node* root);
void printTreePositions(node* root);
