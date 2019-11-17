#include <iostream>
#include <stdlib.h>

#include "binarySearchTrees.h"

void insert_into(node* root,int value){
  node tmp = (node)malloc(sizeof(struct Node));
  tmp = (*root);
  while(tmp!=NULL){
      if(value < tmp->value){
        if(tmp->leftchild == NULL){
          node root1 = (node)malloc(sizeof(struct Node));
          root1->leftchild = NULL;
          root1->rightchild = NULL;
          root1->value = value;
          tmp->leftchild = root1;
          return;
        }
        tmp = tmp->leftchild;
      }else{
        if(tmp->rightchild == NULL){
          node root1 = (node)malloc(sizeof(struct Node));
          root1->leftchild = NULL;
          root1->rightchild = NULL;
          root1->value = value;
          tmp->rightchild = root1;
          return;
        }
        tmp = tmp->rightchild;
      }
    }
}

void printTree(node* root){
  if(*root !=NULL){
    printTree(&((*root)->leftchild));
    cout << (*root)->value << " \n";
    printTree(&((*root)->rightchild));
  }
}

void free_tree(node root){
  if(root != NULL){
    free_tree(root->leftchild);
    free_tree(root->rightchild);
    free(root);
  }
}

size_t size_of(const node root){
  if(root != NULL){
    size_t leftChildren,rightChildren;
    if(root->leftchild != NULL){
      leftChildren = size_of(root->leftchild);
    }else{
      leftChildren = 0;
    }
    if(root->rightchild != NULL){
      rightChildren = size_of(root->rightchild);
    }else{
      rightChildren = 0;
    }
    return leftChildren+rightChildren+1; //add this node to the general sum
  }else{
    return 0;
  }
}

int* contents_of(const node root){
  int* array = (int*)malloc(size_of(root)*sizeof(int));
  node tmp = (node)malloc(sizeof(struct Node));
  tmp = root;

  array = addNodeToArray(tmp,array,0);

  return array;
}

int* addNodeToArray(node root,int* array,int nodesInserted){

  if(root == NULL){
    return array;
  }else{

    array = addNodeToArray(root->leftchild,array,nodesInserted);

    array[nodesInserted + size_of(root->leftchild)] = root->value;

    array = addNodeToArray(root->rightchild,array,nodesInserted + 1 + size_of(root->leftchild));

    return array;
  }
}

const node second_min_in(const node root){
  node tmp = (node)malloc(sizeof(struct Node));
  node parent = (node)malloc(sizeof(struct Node));
  tmp = root;
  while(tmp->leftchild != NULL){
    parent = tmp;
    tmp = tmp->leftchild;
  }
  if(tmp->rightchild == NULL){
    return parent;
  }else{
    tmp = tmp->rightchild;
    while(tmp->leftchild != NULL){
      tmp = tmp->rightchild;
    }
    return tmp;
  }
}
