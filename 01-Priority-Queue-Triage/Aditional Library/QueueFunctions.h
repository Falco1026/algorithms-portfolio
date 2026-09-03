//
// Created by Falcotaku on 26/08/2026.
//

#ifndef QUESTION_1_QUEUEFUNCTIONS_H
#define QUESTION_1_QUEUEFUNCTIONS_H

void buildQueue(struct Queue & q);
void enqueue(struct Queue & q, const struct QueueElement & element);
struct QueueElement dequeue(struct Queue & q);
bool isEmpty(const struct Queue & q);
void printQueue(const struct Queue & q);

#endif //QUESTION_1_QUEUEFUNCTIONS_H