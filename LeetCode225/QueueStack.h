//
//  QueueStack.h
//  LeetCode225
//
//  Created by njim3 on 2018/12/17.
//  Copyright © 2018 njim3. All rights reserved.
//

#ifndef QueueStack_h
#define QueueStack_h

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* dataArr;
    
    int front, rear;
    int size;
} Queue;

typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;

Queue* queueCreate(int maxSize);
bool queueIsEmpty(Queue* queue);
bool queueIsFull(Queue* queue);
int queueTop(Queue* queue);
int queuePop(Queue* queue);
void queuePush(Queue* queue, int val);


/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize);

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x);

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj);

/** Get the top element. */
int myStackTop(MyStack* obj);

int myStackSize(MyStack* obj);

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj);

void myStackFree(MyStack* obj);



#endif /* QueueStack_h */
