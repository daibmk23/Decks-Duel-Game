/**
* Title: AVL Trees & Heap
* Author: Daib Malik
* ID: 22201013
* Section : 1
* Homework: 2
* Description : Implementation of AVL tree
*/

#include "AVL.h"
void AVL::insert(int value){
    insertWithNode(value, root);
}

void AVL::insertWithNode(int value, TreeNode*& node) {
    if (node == nullptr) {
        node = new TreeNode{ value };
    }
    else if (value < node->value) {
        insertWithNode(value, node->left);
    }
    else {
        insertWithNode(value, node->right);
    }
    balance(node);
}


void AVL::remove(int value){
    removeWithNode(value, root);
}

void AVL::removeWithNode(int value, TreeNode*& node){
    if (node == nullptr)
        return;

    if (value < node->value){
        removeWithNode(value, node->left);
    }
    else if (node->value < value){
        removeWithNode(value, node->right);
    }
    else if (node->left != nullptr && node->right != nullptr){
        node->value = findMinimum(node->right)->value;
        removeWithNode(node->value, node->right);
    }
    else {
        TreeNode* prevNode = node;
        if (node->left != nullptr){
            node = node->left;
        }
        else{
            node = node->right;
        }
        delete prevNode;
    }

    balance(node);
}

void AVL::balance(TreeNode*& node){
    if (node == nullptr)
        return;

    if (height(node->left) - height(node->right) > 1){
        if (height(node->left->left) >= height(node->left->right)){
            rotateLeft(node);
        }
        else{
            LLrotate(node);
        }
    }
    else if (height(node->right) - height(node->left) > 1){
        if (height(node->right->right) >= height(node->right->left)){
            rotateRight(node);
        }
        else{
            RRrotate(node);
        }
    }

    if (height(node->left) > height(node->right)){
        node->height = height(node->left) + 1;
    }
    else{
        node->height = height(node->right) + 1;
    }
}

void AVL::rotateLeft(TreeNode*& node){
    TreeNode* temp = node->left;
    node->left = temp->right;
    temp->right = node;

    if (height(node->left) > height(node->right)){
        node->height = height(node->left) + 1;
    }
    else{
        node->height = height(node->right) + 1;
    }

    if (height(temp->left) > node->height){
        temp->height = height(temp->left) + 1;
    }
    else{
        temp->height = node->height + 1;
    }
    node = temp;
}

void AVL::rotateRight(TreeNode*& node){
    TreeNode* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    if (height(node->left) > height(node->right)){
        node->height = height(node->left) + 1;
    }
    else{
        node->height = height(node->right) + 1;
    }

    if (height(temp->right) > node->height){
        temp->height = height(temp->right) + 1;
    }
    else{
        temp->height = node->height + 1;
    }

    node = temp;
}

void AVL::LLrotate(TreeNode*& node){
    rotateRight(node->left);
    rotateLeft(node);
}

void AVL::RRrotate(TreeNode*& node){
    rotateLeft(node->right);
    rotateRight(node);
}

TreeNode* AVL::findMinimum(TreeNode* node) const{
    if (node == nullptr)
        return nullptr;

    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

TreeNode* AVL::getRoot(){
    return root;
}

void AVL::destroy() {
    destroyRecursive(root);
    root = nullptr;
}

void AVL::destroyRecursive(TreeNode* currentNode) {
    if (currentNode == nullptr){
        return;
    }
    destroyRecursive(currentNode->left);
    destroyRecursive(currentNode->right);
    delete currentNode;
}

TreeNode* AVL::findNextGreater(int objectCompare) const {
    TreeNode* current = root;
    TreeNode* nextNode = nullptr;

    while (current != nullptr) {
        if (current->value > objectCompare) {
            nextNode = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nextNode;
}

TreeNode* AVL::findNextSmaller(int value) {
    TreeNode* current = root;
    TreeNode* result = nullptr;

    while (current != nullptr) {
        if (current->value < value) {
            result = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return result;
}
