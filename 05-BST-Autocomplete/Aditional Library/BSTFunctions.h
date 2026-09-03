//
// Created by Falcotaku on 26/08/2026.
//

#ifndef QUESTION_5_BSTFUNCTIONS_H
#define QUESTION_5_BSTFUNCTIONS_H

void buildTree(struct BST & tree);
bool isEmptyTree(const struct BST & tree);
bool isEmptyNode(const struct BSTNode * node);
void plantBSTNode(struct BSTNode *& node, struct BSTNode * left, const struct BSTElement & element, struct BSTNode * right);

void printNode(struct BSTNode * root);
void inOrderTraversal(const struct BST & tree);
void inOrderRecursive(struct BSTNode * node);

void insert(struct BST & tree, const struct BSTElement & element);
void insertRecursive(struct BSTNode *& root, const struct BSTElement & element);

#endif //QUESTION_5_BSTFUNCTIONS_H