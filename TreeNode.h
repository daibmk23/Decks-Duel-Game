/**
* Title: AVL Trees & Heap
* Author: Daib Malik
* ID: 22201013
* Section : 1
* Homework: 2
* Description : Implementation of TreeNode
*/
#ifndef HW2_202_TREENODE_H
#define HW2_202_TREENODE_H

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int val, TreeNode* lt = nullptr, TreeNode* rt = nullptr, int h = 0)
            : value{ val }, left{ lt }, right{ rt }, height{ h } { }
};



#endif //HW2_202_TREENODE_H
