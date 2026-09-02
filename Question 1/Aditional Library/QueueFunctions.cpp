//
// Created by Falcotaku on 26/08/2026.
//

#include "QueueFunctions.h"
#include <iostream>
#include "Queue.h"

using namespace std;

void buildQueue(struct Queue & q){
    q.front = nullptr;
    q.rear = nullptr;
    q.length = 0;
}

int getLength(const struct Queue & q) {
    return q.length;
}

void enqueue(struct Queue & q, const struct QueueElement & element){
    struct QueueNode * newNode = new QueueNode{};
    newNode->element = element;

    // if empty, front and rear are the same guy
    if(isEmpty(q)){
        q.front = newNode;
        q.rear = newNode;
    } else {
        // just add it to the back
        q.rear->next = newNode;
        q.rear = newNode;
    }
    q.length++;
}

struct QueueElement dequeue(struct Queue & q){
    struct QueueNode * outNode = q.front;
    struct QueueElement element = outNode->element;

    // move front to the next guy
    q.front = q.front->next;
    q.length--;

    delete outNode; // free memory!
    return element;
}

bool isEmpty(const struct Queue & q){
    return q.front == nullptr;
}

void printQueue(const struct Queue & q) {
    if (isEmpty(q)) {
        cout << "Queue is empty, nothing to see here" << endl;
    } else {
        struct QueueNode * current = q.front;
        bool isFirst = true;
        cout << "[";

        while (current != nullptr) {
            if (!isFirst) cout << ", ";
            isFirst = false;

            cout << current->element.id;
            current = current->next; // move forward
        }
        cout << "]" << endl;
    }
}