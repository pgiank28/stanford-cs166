#include <iostream>
#include "skyline.h"

node buildingCartesianTree(vector<int> array){
  int i=0;

  node cartessianTree = (node)malloc(array.size()*(sizeof(struct nodes)));

  for(vector<int>::iterator it = array.begin(); it!= array.end(); ++it){
    node nw =(node)malloc(sizeof(struct nodes));
    nw->value = *it;
    nw->position = i;
    cartessianTree = expandTree(cartessianTree,nw);
    i=i+1;
  }

  return cartessianTree;
}

node expandTree(node tree,node n){
  if(!tree){
    return n;
  }
  node root = tree;
  node parent = (node)malloc(sizeof(struct nodes));

  while((n->value) > (tree->value)){
    parent = tree;
    if((n->position) < (tree->position)){
      tree = tree->leftChild;
    }else{
      tree = tree->rightChild;
    }

  }

  if((n->position)>(tree->position)){
    n->leftChild = tree;
  }else{
    n->rightChild = tree;
  }

  if((n->position)>(parent->position)){
    parent->rightChild = n;
  }else{
    parent->leftChild = n;
  }

  return root;
}
