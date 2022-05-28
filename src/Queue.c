#include "queue.h"

Queue * initQueue(int capacity) {
    Queue * queue = (Queue*) malloc(sizeof(Queue));
    queue->array = (int*) calloc(capacity, sizeof(int));
    queue->capacity = capacity;
    queue->rear = -1;
    return queue;
}

int queue_is_full(Queue * queue) {
    return queue->rear == queue->capacity - 1;
}

int queue_is_empty(Queue * queue) {
    return queue->rear == -1;
}

int queue_enqueue(Queue * queue, int data) {
    if(!queue_is_full(queue)) {
        queue->array[++queue->rear] = data;
        return 1;
    }
    return 0;
}

int queue_dequeue(Queue * queue) {
    if(!queue_is_empty(queue)) {
        int data = queue->array[0];
        for(int i = 0; i < queue->rear; i++) {
            queue->array[i] = queue->array[i + 1];
        }
        queue->rear--;
        return data;
    }
    return INT_MIN;
}

void queue_destroy(Queue * queue) {
    free(queue->array);
    free(queue);
}