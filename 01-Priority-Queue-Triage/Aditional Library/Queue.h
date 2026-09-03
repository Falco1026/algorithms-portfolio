//
// Created by Falcotaku on 26/08/2026.
//

#ifndef QUESTION_1_QUEUE_H
#define QUESTION_1_QUEUE_H
#include "QueueNode.h"

struct Queue {
    struct QueueNode * front; // head of queue
    struct QueueNode * rear;  // tail of queue
    int length;               // how many inside
};

#endif //QUESTION_1_QUEUE_H