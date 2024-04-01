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


