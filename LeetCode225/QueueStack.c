//
//  QueueStack.c
//  LeetCode225
//
//  Created by njim3 on 2018/12/17.
//  Copyright © 2018 njim3. All rights reserved.
//

#include "QueueStack.h"

Queue* queueCreate(int maxSize) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    
    queue->front = queue->rear = -1;
    queue->size = maxSize;
    
    queue->dataArr = (int*)malloc(sizeof(int) * maxSize);
    
    return queue;
}

bool queueIsEmpty(Queue* queue) {
    if (queue->front == -1 && queue->rear == -1)
        return true;
    
    return false;
}

bool queueIsFull(Queue* queue) {
    if (queue->rear == queue->size - 1)
        return true;
    
    return false;
}

int queueTop(Queue* queue) {
    if (queueIsEmpty(queue))
        return -1;
    
    return queue->dataArr[queue->front];
}

int queuePop(Queue* queue) {
    if (queueIsEmpty(queue))
        return -1;
    
    int firstData = queue->dataArr[queue->front];
    
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        ++queue->front;
    
    return firstData;
}

void queuePush(Queue* queue, int val) {
    if (queueIsFull(queue)) {
        printf("The queue is full!");
        
        return ;
    }
    
    if (queueIsEmpty(queue)) {
        ++queue->front;
        ++queue->rear;
    } else
        ++queue->rear;
    
    queue->dataArr[queue->rear] = val;
}


/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    
    stack->q1 = queueCreate(maxSize);
    stack->q2 = queueCreate(maxSize);
    
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    queuePush(obj->q2, x);
    
    while (!queueIsEmpty(obj->q1)) {
        int data = queuePop(obj->q1);
        
        queuePush(obj->q2, data);
    }
    
    // exchange q1 and q2
    Queue* tmp = obj->q1;
    
    obj->q1 = obj->q2;
    obj->q2 = tmp;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (queueIsEmpty(obj->q1))
        return -1;
    
    return queuePop(obj->q1);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (queueIsEmpty(obj->q1))
        return -1;
    
    return queueTop(obj->q1);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return queueIsEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}
