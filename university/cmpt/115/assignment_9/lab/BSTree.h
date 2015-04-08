// File: BSTree.h
// CMPT 115/117 2014.T2.Lab9
// Defines the BSTree class 

#ifndef _BS_TREE_H_
#define _BS_TREE_H_

#include "TreeNode.h"

class BSTree {
    TreeNode *root;
    int numElements;

  // some private methods: available to BSTree objects, but no one else!
  
    TreeNode *insertNodeBST(TreeNode *t, Element nData);
    bool searchNodeBST(TreeNode *t, Element target, Element *rDataOut);
    void preorder(TreeNode *t);
    void inorder(TreeNode *t);
    void postorder(TreeNode *t);
    void displayElement(TreeNode *t);
    int maxNodeDepth(TreeNode *t, int);

  public: 
    BSTree();
    ~BSTree();
    void destroyTree(TreeNode *t);
     
    void displayInOrder();
    void displayPreOrder();
    void displayPostOrder();
    
    // you have to implement all the following methods!   
    void insertBST(Element nData);
    bool searchBST(Element target, Element *rDataOut);
    bool deleteBST(Element nData, Element *rDataOut);
    int maxDepth();

};

#endif // _BS_TREE_H_
