//Firaol Berehanu
// march 16 2024
//This is a binary search tree wich have children and u can add remove or print 

//inlducde stuff
#include "node.h"
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

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
void recurciveAdd(Node* curr, int value) {//ading to the tree 
  if (curr->data >= value && curr->getLeft() == NULL) {//curr is greater than value and its left is empty
    curr->setLeft(new Node(value));
    curr->getLeft()->parent = curr;
  }
  else if (curr->data < value && curr->getRight() == NULL) {// curr is less than value and its right is empty
    curr->setRight(new Node(value));
    curr->getRight()->parent = curr;
  }
  else if (curr->data >= value) {//currs data is greater than the value still
    recurciveAdd(curr->getLeft(), value);
  }
  else if (curr->data < value) {// currs data is less than the value still
    recurciveAdd(curr->getRight(), value);
  }
}
void addFile(Node* &root) {//Adds from a file
  cout << "how many numbers to add" << endl;
  int input;
  cin >> input;
  
  for (int i = 0; i < input; i++) {
    char input[10];
    char tempString[10];
    int count = 1;
    int numput;
    int randomnum = (rand() % 50) + 1;
    fstream myfile("numberFile.txt");//Opens file
       
    while (myfile.getline(input,10, ' ')) {
      if (count == randomnum) {
	strcpy(tempString, input);
	count++;
      }
      count++;
    }
    numput = atoi(tempString);//Changes from string to int
    
    if (root == NULL) {//If the tree has nothing
      root = new Node(numput);
      root->parent = NULL;
    }
    else if (root != NULL) {//If there is something in the tree
      recurciveAdd(root, numput);
    }
  }
}
bool search(Node* curr, int num, Node* &newptr) {//Looks for the number in the tree and returns true or false based on if it can find it or not
  bool b = false;
  if (curr->data == num) {//Base case
    newptr = curr;
    return true;
  }
  else {
    if (curr->data > num && curr->getLeft() != NULL) {//Traverses the binary tree if curr data is still more than the target num and there is still a left
      b = search(curr->getLeft(), num, newptr);
    }
    else if (curr->data < num && curr->getRight() != NULL) {//Traverses the binary tree if curr data is still less than target num and there is a right
      b = search(curr->getRight(), num, newptr);
    }
    if(b) {
      return true;
    }
  }
  return false;
}

void display(Node* curr, int depth) {//Displays the binary search tree using tabs
  if (curr->right != NULL) {
    display(curr->right, depth + 1);//Recurcive call
  }
  for (int i = 0; i < depth; i++) {//Prints out the amount of tabs based on the depth
    cout << "\t";
  }
  cout << curr->data << endl;//Prints out the number
  if (curr->left != NULL) {
    display(curr->left, depth + 1);//Recurcive call
  }
}

void remove(Node* &root, Node* curr, int num, Node* newptr) {//Removes the number from the binary search tree
  if (search(curr, num, newptr) == true) {//If the number is in the tree
    Node* temp = newptr;
    if (temp == root) {//If thr root is the number to be deleted
      if (temp->getLeft() == NULL && temp->getRight() == NULL) {//If it is a leaf
	root = NULL;
	newptr = NULL;
      }
      else if (temp->getLeft() != NULL && temp->getRight() == NULL) {//If it only has a left child
	root = root->getLeft();
	newptr = NULL;
      }
      else if (temp->getLeft() == NULL && temp->getRight() != NULL) {//If it only has a right child
	root = root->getRight();
	newptr = NULL;
      }
      else {//If it has two children
	Node* newNode = temp->right;
        while (newNode->left != NULL) {
          newNode = newNode->left;
        }
        temp->data = newNode->data;
        if (newNode == temp->getRight()) {
          temp->right = temp->right->right;
        }
	newptr = NULL;
      }
    }
    else {
      if (temp->getLeft() == NULL && temp->getRight() == NULL) {//If the it is a leaf
	if (temp->parent->getLeft() == temp) {//If temp is a left child of its parents delete it and make its parents left point to null
	  temp->parent->left = NULL;
	  delete temp;
	}
	else {//If right child
	  temp->parent->right = NULL;
	  delete temp;
	}
	newptr = NULL;
      }
      else if (temp->getLeft() != NULL && temp->getRight() == NULL) {//If temp only has a left child
	//MAKEs THE PARENTS POINTER POINT TO THE CHILD (EASIER)
	Node* tempParent = temp->parent;
	if (tempParent->getLeft() == temp) {//If it is a left child
	  tempParent->left = temp->getLeft();
	  temp->getLeft()->parent = tempParent;
	}
	else {//If it is a right child
	  tempParent->right = temp->getLeft();
	  temp->getLeft()->parent = tempParent;
	}
	delete temp;//Deletes temp
	newptr = NULL;
      }
      else if (temp->getLeft() == NULL && temp->getRight() != NULL) {//If temp only has a right child
	Node* tempParent = temp->parent;
	if (tempParent->getLeft() == temp) {//If it is a right child
	  tempParent->left = temp->getRight();
	  temp->getRight()->parent = tempParent;
	}
	else {//If it is a right child
        tempParent->right = temp->getRight();
        temp->getRight()->parent = tempParent;
      }
	delete temp;
	newptr = NULL;
      }
      else {//If it has two children
	Node* newNode = temp->right;
	while (newNode->left != NULL) {
	  newNode = newNode->left;
	}
	temp->data = newNode->data;
	if (newNode == temp->getRight()) {
	  temp->right = temp->right->right;
	}
      }
    }
  }
}
int main() {
  srand(time(0));
  cout << "Binary Search Tree" << endl;
  
  Node* root = NULL;
  bool playing = true;
  Node* newptr = NULL;
  
  while (playing == true) {//While loop
    
    cout << "you wanna  add from a file(ADD), Manualy add(TYPE), search(SEARCH), display(DISPLAY), remove from heap(REMOVE), or quit(QUIT)" << endl;
    char input[10];
    cin >> input;
    
    if (strcmp(input, "ADD") == 0) {//Calls the add function
      addFile(root);
    }
    else if (strcmp(input, "TYPE") == 0) {//Calls type function
      manualAdd(root);
    }
    else if (strcmp(input, "DISPLAY") == 0) {//Calls display function
      display(root, 0);
    }
    else if (strcmp(input, "SEARCH") == 0) {//Calls the search function and asks for what you want to search
      cout << "What number would you liek to search" << endl;
      int input2;
      cin >> input2;
      bool a = search(root, input2, newptr);
      if (a == true) {
	cout << "number in tree" << endl;
      }
      else {
	cout << "number not in tree" << endl;
      }
    }
    else if (strcmp(input, "REMOVE") == 0) {//Calls remove function and asks what you want to remove
      cout << "what number would you like to remove" << endl;
      int input3;
      cin >> input3;
      remove(root, root, input3, newptr);
    }
    else if (strcmp(input, "QUIT") == 0) {//Returns false
      playing = false;//Exits while Loop stopping game
    }
  }
}

