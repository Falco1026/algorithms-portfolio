#include <iostream>
#include "Aditional Library/Queue.h"
#include "Aditional Library/QueueFunctions.h"
using namespace std;

// kept strings in Spanish to match the exam output format!
void printPriority(const struct Queue & q) {
    if (isEmpty(q)) {
        cout << "La cola esta vacia no se puede mostrar" << endl;
    } else {
        struct QueueNode * current = q.front;
        int i = 1;
        while (current != nullptr) {
            cout << "Turno " << i <<": Ticket #"<< current->element.id
                 <<" [Gravedad = "<< current->element.gravity
                 << ", Edad = " << current->element.age
                 << ", Llego = " << current->element.arrivalTime << "]" << endl;
            current = current->next;
            i++;
        }
    }
}

void enqueueWithPriority(Queue & q, QueueElement newElem) {
    Queue auxQueue;
    buildQueue(auxQueue);
    bool inserted = false;

    // move elements to auxQueue and find the spot for newElem
    while (!isEmpty(q)) {
        QueueElement currentElem = dequeue(q);

        // check if newElem has higher priority than currentElem
        bool higherGravity = (newElem.gravity > currentElem.gravity);
        bool sameGravYounger = (newElem.gravity == currentElem.gravity && newElem.age < currentElem.age);
        bool sameGravSameAgeFaster = (newElem.gravity == currentElem.gravity && newElem.age == currentElem.age && newElem.arrivalTime < currentElem.arrivalTime);

        // if we found its place, put newElem first
        if (!inserted && (higherGravity || sameGravYounger || sameGravSameAgeFaster)) {
            enqueue(auxQueue, newElem);
            inserted = true;
        }

        // put the old element right after
        enqueue(auxQueue, currentElem);
    }

    // if it has the lowest priority, goes at the end
    if (!inserted) {
        enqueue(auxQueue, newElem);
    }

    // put everything back to original queue
    while (!isEmpty(auxQueue)) {
        enqueue(q, dequeue(auxQueue));
    }
}

int main() {
    Queue mainQueue;
    buildQueue(mainQueue);
    QueueElement elem;

    // test case 1
    elem.id = 101; elem.gravity = 5; elem.age = 40; elem.arrivalTime = 800;
    enqueueWithPriority(mainQueue, elem);

    // test case 2
    elem.id = 102; elem.gravity = 9; elem.age = 25; elem.arrivalTime = 801;
    enqueueWithPriority(mainQueue, elem);

    // test case 3
    elem.id = 103; elem.gravity = 9; elem.age = 60; elem.arrivalTime = 810;
    enqueueWithPriority(mainQueue, elem);

    // test case 4
    elem.id = 104; elem.gravity = 9; elem.age = 8;  elem.arrivalTime = 811;
    enqueueWithPriority(mainQueue, elem);

    // output should match the exam expected output
    printPriority(mainQueue);
    return 0;
}