#include <iostream>
#include <iomanip>
#include "BST.h"
#include "BSTFunctions.h"

using namespace std;

// starts the recursive insertion
void insert(struct BST & tree, const struct BSTElement & element) {
    insertRecursive(tree.root, element);
}

// recursive magic to find the right spot
void insertRecursive(struct BSTNode *& root, const struct BSTElement & element){
    if(isEmptyNode(root)) {
        // found an empty spot, plant it here!
        plantBSTNode(root, nullptr, element, nullptr);
    } else {
        // go left if smaller
        if(root->element.spanish > element.spanish)
            insertRecursive(root->left, element);
        // go right if bigger
        else if(root->element.spanish < element.spanish)
            insertRecursive(root->right, element);
        else
            cout << "Bro, " << element.spanish << " is already in the tree!" << endl;
    }
}

// setup an empty tree
void buildTree(struct BST & tree) {
    tree.root = nullptr;
}

bool isEmptyTree(const struct BST & tree) {
    return tree.root == nullptr;
}

bool isEmptyNode(const struct BSTNode * node) {
    return node == nullptr;
}

// creates a new node in memory
void plantBSTNode(struct BSTNode *& node, struct BSTNode * left,
                  const struct BSTElement & element, struct BSTNode * right) {
    struct BSTNode * newNode = new struct BSTNode;
    newNode->right = right;
    newNode->left = left;
    newNode->element = element;
    node = newNode; // link it back
}

void printNode(struct BSTNode * root) {
    cout << setw(5) << root->element.spanish;
}

void inOrderTraversal(const struct BST & tree) {
    inOrderRecursive(tree.root);
}

// Left -> Node -> Right (gives alphabetical order)
void inOrderRecursive(struct BSTNode * node) {
    if (!isEmptyNode(node)) {
        inOrderRecursive(node->left);
        printNode(node);
        inOrderRecursive(node->right);
    }
}