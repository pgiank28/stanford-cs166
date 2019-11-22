#include <bits/stdc++.h>
using namespace std;

struct nodes{
  int value;
  int position;
  nodes* leftChild;
  nodes* rightChild;
};


typedef struct nodes* node;

node buildingCartesianTree(vector<int> array);
int findMinimumValue(int leftPos,int rightPos);
void expandTree(node* tree,node n);
void printTree(node* root);
void printTreePositions(node* root);
