#ifndef STACK_H
#define STACK_H

////////////////////////////////////////////////////////////////////////////////
// Include Files
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Type Definitions 
// struct
      //structstack  named stack
typedef struct stack stack;

////////////////////////////////////////////////////////////////////////////////
//Function Declerations

//purpose: creates a new stack and returns it
//return: a pointer to a new stack
stack* stack_create(); //this can fail if we can't do memory.

//purpose:destroys a stack
//return: n/a
void stack_destroy(stack** s);

//purpose: adds an element to the stack
//return: n/a
void stack_push(stack* s, void* element);

//puprose: returns most recently added stack element
//return: the element that has been removed
void* stack_pop(stack* s); //can fail if empty stack.

//purpose: returns true if stack is empty, false otherwise.
//return value: boolean to indicate if empty.
int stack_is_empty(stack* s);

//purpose: returns the number of elements in the stack
//return: number of elements in the stack
int stack_size(stack* s);

//purpose: displays the contents of the stack as integers starting at the top.
//return: n/a
void stack_display(stack* s);

#endif