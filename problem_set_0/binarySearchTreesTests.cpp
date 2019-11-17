#include <iostream>
#include <stdlib.h>
#include "binarySearchTrees.h"

int main(){
  node root = (node)malloc(sizeof(struct Node));
  root->leftchild = NULL;
  root->rightchild = NULL;
  root->value = 9;

  insert_into(&root,4);
  insert_into(&root,6);
  insert_into(&root,17);
  insert_into(&root,12);
  insert_into(&root,-8);
  insert_into(&root,11);
  insert_into(&root,14);

  cout << "size of tree: " << size_of(root) << " \n";


  int* tel = contents_of(root);
  cout << "Ordered tree values: " ;
  size_t i;
  for(i=0;i<size_of(root);i++){
    cout << tel[i] << "  ";
  }


  node sec = second_min_in(root);
  cout << "\nSecong smallest value: " << sec->value << " \n";


  free_tree(root);
  return 0;
}
