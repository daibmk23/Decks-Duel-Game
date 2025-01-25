/**
* Title: AVL Trees & Heap
* Author: Daib Malik
* ID: 22201013
* Section : 1
* Homework: 2
* Description : Header file for AVL
*/

#ifndef HW2_202_AVL_H
#define HW2_202_AVL_H
#include "TreeNode.h"

class AVL {
private:
    TreeNode* root;

    int height(TreeNode* node) const {
        if (node == nullptr){
            return -1;
        }
        return node->height;
    }
    void rotateLeft(TreeNode*& node);
    void rotateRight(TreeNode*& node);
    void LLrotate(TreeNode*& node);
    void balance(TreeNode*& node);
    void RRrotate(TreeNode*& node);
    void insertWithNode(int value, TreeNode*& node);
    void removeWithNode(int value, TreeNode*& node);
    TreeNode* findMinimum(TreeNode* node) const;


public:
    AVL() {
        root = nullptr;
    }
    TreeNode* getRoot();
    void insert(int value);
    void remove(int value);
//    void display() const;
//    std::vector<int> toArrayRepresentation() const;
//    void displayAsArray() const;
    void destroyRecursive(TreeNode *currentNode);
    void destroy();
    TreeNode *findNextGreater(int objectCompare) const;
//    int findLargestLessThanHelper(TreeNode *node, int target) const;
//    int findLargestLessThan(int target) const;
    TreeNode *findNextSmaller(int value);
};


#endif //HW2_202_AVL_H
