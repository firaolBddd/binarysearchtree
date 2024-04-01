//Firaol Berehanu
// march 16 2024
//This is a binary search tree wich have children and u can add remove or print 

//inlducde stuff
#include "node.h"
#include <fstream>
#include <math.h>
#include <stdio.h>

//Function prototypes
void manualAdd(Node* &root);
void recurciveAdd(Node* curr, int value);
bool search(Node* curr, int num, Node* &newptr);
void display(Node* curr, int depth);
void addFile(Node* &root);
void remove(Node* &root, Node* curr, int num, Node* newptr);

void manualAdd(Node* &root) {//adds the number manualy on the tree
  cout << "enter a number between 1-999" << endl;
  int num;
  cin >> num;
  if (root == NULL) {//when ther nuthin in the tree
    root = new Node(num);
    root->parent = NULL;
  }
  else if (root != NULL) {//when the tree or list dose have somitng 
    recurciveAdd(root, num);
  }
}

