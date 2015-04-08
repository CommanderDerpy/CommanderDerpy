/* 
 * Maximilian Gewers 
 * 11163599
 * CMPT - 115 - 02
 * CMPT - 115 - T08
 */

// File: BSTree.cc
// CMPT 115/117 2014.T2.Lab9
// Implements the BSTree class operations

#include <iostream>
using namespace std;

#include "BSTree.h"
//#include "TreeNode.h"

//------------------------------------------------------------
// constructor
BSTree::BSTree()
{
  root = NULL;
  numElements = 0;
}

//------------------------------------------------------------
// destructor
BSTree::~BSTree(){
  if (root != NULL){
    destroyTree(root);
  }
}


// Algorithm destroyTree(t)
// private function to destroy the whole tree
// Pre: t is a referene to a TreeNode
// Post: the whole tree at t is deallocated

void BSTree::destroyTree(TreeNode *t)
{
  if (t == NULL) {
     return;
  }
  else {
     destroyTree(t->getLeft());
     destroyTree(t->getRight());
     delete t;
  }
}


//------------------------------------------------------------
// Algorithm insertNodeBST
// private method to insert a new Element
// Pre: given a new TreeNode
// Post: the tree contains the element in ascending binary search position

TreeNode * BSTree::insertNodeBST(TreeNode *t, Element dataIn){
  // this is just a stub; complete this function
  if (t == NULL) {
      TreeNode *rNew = new TreeNode(dataIn);
      return rNew;
  } else if (dataIn == t->getData()) {
      return t;
  } else if (dataIn < t->getData()) {
      //rNode ∗⇒ leftSubtree ← insertNodeBST(rNode ∗⇒ leftSubtree, nData)
      t->setLeft(insertNodeBST(t->getLeft(),dataIn));
      return t;
  } else if (dataIn > t->getData()) {
      //rNode ∗⇒ rightSubtree ← insertNodeBST(rNode ∗⇒ rightSubtree, nData)
      t->setRight(insertNodeBST(t->getRight(),dataIn));
      return t;
  }
  return NULL;
}

// Algorithm insertBST(dataIn)
// Pre: dataIn is a new Element
// Post: inserts dataIn into the BSTree
void BSTree::insertBST(Element dataIn){
    root = insertNodeBST(root,dataIn);
}


//------------------------------------------------------------
// helper function of SearchBST for inner use
// Pre: rNode :: refToTreeNode
//     target :: Integer
// Post: tree is unchanged
// Return: true if target is found in the tree; false otherwise.
bool BSTree::searchNodeBST(TreeNode *rNode, Element target, Element *rDataOut){
  // this is just a stub; complete this function
  if (rNode == NULL) {
    return false;
  } else if (target < rNode->getData()) {
      return searchNodeBST(rNode->getLeft(),target,rDataOut);
  } else if (target > rNode->getData()) {
      return searchNodeBST(rNode->getRight(),target,rDataOut);
  } else {
    *rDataOut = rNode->getData();
  }
  return true;
}


// Algorithm searchBST(target, rDataOut)
// Pre: target is an Element, rDataOut is a reference to a valid Element
// Post: copies the value if target is found
// Return: true if target is in the BSTree, false otherwise 
bool BSTree::searchBST(Element target, Element *rDataOut){
  // this is just a stub; complete this function
  return searchNodeBST(root,target,rDataOut);
}


//------------------------------------------------------------
// Algorithm deleteBST(target, rDataOut)
// Pre: target is an Element, rDataOut is a reference to a valid Element
// Post: copies the value if target is found
//       and removes the target node from the BSTree
// Return: true if target was in the BSTree, false otherwise 
bool BSTree::deleteBST(Element target, Element *rDataOut){
  // this is just a stub; complete this function
  TreeNode *rNode = root;
  TreeNode *rParent = NULL;
  TreeNode *rNew;
  TreeNode *rBiggest;

  while (rNode != NULL && rNode->getData() != target) {
      rParent = rNode;
      if (target < rNode->getData()) {
          rNode = rNode->getLeft();
      } else {
          rNode = rNode->getRight();
      }
  }

  if (rNode == NULL) {
  	return false;
  } else {
  	if (rNode->getLeft() == NULL) {
  			rNew = rNode->getRight();
  	} else if (rNode->getLeft() == NULL) {
  			rNew = rNode->getLeft();
  	} else {
  			rBiggest = rNode->getLeft();
  			while (rBiggest->getRight() != NULL) {
  				rBiggest = rBiggest->getRight();
  			}
  			rBiggest->setRight(rNode->getRight());
  			rNew = rNode->getLeft();
  	}
  	if (rNode == root) {
  		root = rNew;
  	} else if (rParent->getLeft() == rNode) {
  		rParent->setLeft(rNew);
  	} else {
  		rParent->setRight(rNew);
  	}

  	(*rDataOut) = rNode->getData();
  	delete(rNode);
  	return true;
  }
}



//------------------------------------------------------------
// private helper function
void BSTree::displayElement(TreeNode *t) {
   cout << t->getData()  << "   ";
}

//------------------------------------------------------------
// Algorithm preorder(rNode)
// private helper function 
// Pre: rNode is a reference to a TreeNode
// Post: displays the whole tree in inorder
void BSTree::inorder(TreeNode * rNode) {
  if (NULL != rNode) {
    inorder(rNode->getLeft());
    displayElement(rNode);
    inorder(rNode->getRight());
  }
}


// Algorithm displayInOrder()
// Post: displays the tree
void BSTree::displayInOrder() {
  if (root == NULL) 
    cout << "Empty";
  else 
    inorder(root);
  cout << endl;
}


//------------------------------------------------------------
// Algorithm preorder(rNode)
// private helper function 
// Pre: rNode is a reference to a TreeNode
// Post: displays the whole tree in preorder

void BSTree::preorder(TreeNode * rNode) {
  if (NULL != rNode) {
    displayElement(rNode);
    preorder(rNode->getLeft());
    preorder(rNode->getRight());
  }
}

// Algorithm displayPreOrder()
// Post: displays the tree
void BSTree::displayPreOrder() {
  if (root == NULL) 
    cout << "Empty";
  else 
    preorder(root);
  cout << endl;
}

//------------------------------------------------------------
// Algorithm preorder(rNode)
// private helper function 
// Pre: rNode is a reference to a TreeNode
// Post: displays the whole tree in postorder
void BSTree::postorder(TreeNode * rNode) {
  if (NULL != rNode) {
    postorder(rNode->getLeft());
    postorder(rNode->getRight());
    displayElement(rNode);
  }
}


// Algorithm displayPostOrder()
// Post: displays the tree
void BSTree::displayPostOrder() {
  if (root == NULL) 
    cout << "Empty";
  else 
    postorder(root);
  cout << endl;
}

// Algorithm 
// Pre: nothing
// Post: calls a private metho
// Return: the count as int of the higest leaf
int BSTree::maxDepth() {
	return maxNodeDepth(root,0);
}

// Algorithm
// Pre: RefToTree :: Ref to the tree which we want to count
//	    int count :: the counter which we are returning
// Post: goes though each leaf and counts up to the higest
// Return: the count as int of the higest leaf
int BSTree::maxNodeDepth(TreeNode *t, int count) {
	cout << t->getData() << endl;
	//cout << count << " this is the count!!!" << endl;
	if (t->getRight() == NULL && t->getLeft() == NULL) { 
		cout << "The depth is: "<< count << endl;
		return count;
	} else if (t->getLeft() != NULL) {
		maxNodeDepth(t->getLeft() ,count + 1);
	}else if (t->getRight() != NULL) {
		maxNodeDepth(t->getRight() ,count + 1);
	}
	return count;
}
