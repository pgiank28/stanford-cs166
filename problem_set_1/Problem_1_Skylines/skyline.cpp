#include <iostream>
#include "skyline.h"

int calculateMaximumSkylineArea(node* cartessianTree){
  if((*cartessianTree)==NULL){
    return 0;
  }
  int r = calculateMaximumSkylineArea(&((*cartessianTree)->rightChild));
  int l = calculateMaximumSkylineArea(&((*cartessianTree)->leftChild));
  int in = ((*cartessianTree)->value)*(findNumberOfChildren(cartessianTree));

  if(r>=l && r>=in){ return r;}
  else{
    if(r<l && in<=l){return l;}
    else{ return in;}
  }
}


int findNumberOfChildren(node* cartessianTree){

  if((*cartessianTree) == NULL){ return 0;}
  int l = findNumberOfChildren(&((*cartessianTree)->leftChild));
  int r = findNumberOfChildren(&((*cartessianTree)->rightChild));
  return l+r+1;
}

int findArea(int x,int y,node* cartessianTree){
  node tmp = (node)malloc(sizeof(struct nodes));
  tmp = (*cartessianTree);
  while(tmp->position < x || tmp->position > y){
    if(tmp->position < x){
      tmp = tmp->rightChild;
    }else{
      tmp = tmp->leftChild;
    }
  }
  return(y-x)*tmp->value;
}

node buildingCartesianTree(vector<int> array){
  int i=0;

  node cartessianTree = (node)malloc(sizeof(struct nodes));
  cartessianTree->value = -1;
  cartessianTree->position = -1;
  cartessianTree->leftChild = NULL;
  cartessianTree->rightChild = NULL;


  for(vector<int>::iterator it = array.begin(); it!= array.end(); ++it){
    node nw =(node)malloc(sizeof(struct nodes));
    nw->value = *it;
    nw->position = i;
    expandTree(&cartessianTree,nw);
    i=i+1;
  }

  return cartessianTree;
}


void expandTree(node* tree,node n){
  node root = (node)malloc(sizeof(struct nodes));
  root = (*tree);

  /*Insertion of the first element*/
  if(root->position == -1){
    root->position = n->position;
    root->value = n->value;
    return;
  }

  node parent = (node)malloc(sizeof(struct nodes));
  int changeHead = 1;

  while(root!=NULL){

    if(root->value > n->value){
      //Here we must insert the new node
      n->leftChild = root;

      if(changeHead == 1){//Occassion where the new element is the smallest and must be inserted as the new root
          (*tree) = n;
          return;
      }else{//The new node must be a right child of the very previous smallest node
          parent->rightChild = n;
          return;
      }

   }else{
      //Here we continue searching for the position in the tree where the new node is to be inserted
      parent = root;
      if(root->rightChild == NULL){
        root->rightChild = n;
        return;
      }else{
        root = root->rightChild;
        changeHead = 0;
      }
    }
   }

}


void printTree(node* root){

  if((*root)!=NULL){
    printTree(&((*root)->leftChild));
    cout << (*root)->value << " \n";
    printTree(&((*root)->rightChild));
  }
}

void printTreePositions(node* root){
  if((*root)!=NULL){
    printTreePositions(&((*root)->leftChild));
    cout << (*root)->position << " \n";
    printTreePositions(&((*root)->rightChild));
  }
}
