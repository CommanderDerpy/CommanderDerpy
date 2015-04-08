// File: TreeNode.h
// CMPT 115/117 2014.T2.Lab9
// Defines the TreeNode class


#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_


typedef int Element;

class TreeNode {
    Element data;
    TreeNode *left;
    TreeNode *right;
  public: 
    TreeNode(Element d);
    ~TreeNode();
    Element getData();
    TreeNode *getLeft();
    TreeNode *getRight();
    void setLeft(TreeNode *l);
    void setRight(TreeNode *r);
};

#endif // _TREE_NODE_H_
