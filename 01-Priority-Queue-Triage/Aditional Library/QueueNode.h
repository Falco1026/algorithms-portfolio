//
// Created by Falcotaku on 26/08/2026.
//

#ifndef QUESTION_1_QUEUENODE_H
#define QUESTION_1_QUEUENODE_H
#include "QueueElement.h"

struct QueueNode {
    struct QueueElement element; // the data
    QueueNode * next;            // link to next bro
};

#endif //QUESTION_1_QUEUENODE_H