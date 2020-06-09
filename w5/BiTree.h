#ifndef BITREE_H
#define BITREE_H

#include "Node.h" 

class BiTree {
	Node *root; 
	void PrintCall(Node*); 
public: 
	BiTree(); 
	void Insert(int); 
	void Print();
	void Print_Min();
	void Print_Max();
};

#endif
