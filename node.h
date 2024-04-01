#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node {//Node Class
 public:
  //Varubles and pointers
  Node* left;
  Node* right;
  Node* parent;
  int data;
  //Prototypes
  Node(int newdata);
  void setLeft(Node* newleft);
  void setRight(Node* newright);
  Node* getLeft();
  Node* getRight();
  Node* getParent();
  int getData();

};

