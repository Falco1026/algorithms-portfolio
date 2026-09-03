//
// Created by Falcotaku on 26/08/2026.
//

#ifndef QUESTION_5_BSTNODE_H
#define QUESTION_5_BSTNODE_H
#include "BSTElement.h"

struct BSTNode {

    struct BSTElement element; // the payload
    struct BSTNode * left;     // left child
    struct BSTNode * right;    // right child
};
#endif //QUESTION_5_BSTNODE_H