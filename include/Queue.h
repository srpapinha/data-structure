#ifndef _QUEUE_H_
#define _QUEUE_H_

#ifndef _LIMITS_H___
#include <limits.h>
#endif

#ifndef _INC_STDLIB
#include <stdlib.h>
#endif

typedef struct Queue {
    int * array;
    int capacity;
    int rear;
} Queue;

Queue * initQueue(int capacity);
int queue_is_full(Queue * queue);
int queue_is_empty(Queue * queue);
int queue_enqueue(Queue * queue, int data);
int queue_dequeue(Queue * queue);
void queue_destroy(Queue * queue);
#endif