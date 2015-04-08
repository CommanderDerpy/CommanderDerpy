// File: TreeNode.cc
// CMPT 115/117 2014.T2.Lab9
// Implements the TreeNode class operations

#include <iostream>

#include "TreeNode.h"

//------------------------------------------------------------
// constructor
TreeNode::TreeNode(Element dataIn)
{
	data  = dataIn;
	left = NULL;
	right = NULL;
}


//------------------------------------------------------------
// destructor
TreeNode::~TreeNode()
{
  // remove the following line once you understand how destructors 
  // get called.  There's no need to litter the console...
  std::cout << "Say goodbye to the node with data: " << data << std::endl;
}


//------------------------------------------------------------
// accessor
// Return: left subtree
Element TreeNode::getData() {
  return data;
}


//------------------------------------------------------------
// accessor
// Return: left subtree
TreeNode *TreeNode::getLeft() {
  return left;
}


//------------------------------------------------------------
// accessor
// Return: right subtree
TreeNode *TreeNode::getRight() {
  return right;
}


//------------------------------------------------------------
// mutator
// Pre: l a reference to a TreeNode
// Post: changes the left subtree to l
void TreeNode::setLeft(TreeNode *l) {
  left = l;
}


//------------------------------------------------------------
// mutator
// Pre: r a reference to a TreeNode
// Post: changes the right subtree to r
void TreeNode::setRight(TreeNode *r) {
  right = r;
}

// end of file
