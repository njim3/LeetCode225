//
//  main.c
//  LeetCode225
//
//  Created by njim3 on 2018/12/17.
//  Copyright © 2018 njim3. All rights reserved.
//

#include "QueueStack.h"

int main(int argc, const char * argv[]) {
    MyStack* stack = myStackCreate(10);
    
    myStackPush(stack, 1);
    myStackPush(stack, 2);
    
    printf("Top stack: %d\n", myStackTop(stack));
    printf("Pop stack: %d\n", myStackPop(stack));
    printf("Stack is empty: %d", myStackEmpty(stack));
    
    myStackFree(stack);
    
    return 0;
}
