#include <gb/gb.h>
#include "stack.h"

////////////////////////////////////////////////////////////////////////////////
// Type Definitions 

typedef struct node node;

struct node{
    void* element;
    node* next;
};

struct stack {
    node* head;
    int size;
};

////////////////////////////////////////////////////////////////////////////////
//Function Declerations

//purpose: creates a new stack and returns it
//return: a pointer to a new stack
stack* stack_create(){
    stack* new_stack = (stack*)malloc(sizeof(stack));
    
    //Memory allocation failed
    if(new_stack == NULL){
        printf("Failed to create stack..\n");
        exit(1);
    }
    //Memory allocation succeeded.
    else{
        new_stack->head = NULL;
        new_stack->size = 0;
        
        return new_stack;
    }
}

//purpose:destroys a stack
//go through and free memory of the entire stack.
//return: n/a
void stack_destroy(stack** s){
    node* iter = (*s)->head;
    
    //frees the internal list
    while(iter != NULL){
        node* n = iter->next;
        free(iter);
        iter = n;
    }
    
    //free stack
    free(*s);
    
    //cleanup after ourselves outside (no dangling pointer).
    *s = NULL;
}

//purpose: adds an element to the stack
//return: n/a
void stack_push(stack* s, void* element){
    node* new_node = (node*)malloc(sizeof(node));
    
    //setup node
    new_node->element = element;
    new_node->next = s->head;
    
    //attach node
    s->head = new_node;
    s->size++;
    
}

//puprose: returns most recently added stack element
//return: the element that has been removed
void* stack_pop(stack* s){
    
    if(s->size == 0){
        //printf("Tried to pop from empty stack.\n");
        //exit(1);
        return NULL;
    }
    
    node* active_node = s->head;
    void* data = active_node->element;
    
    //update stack
    s->head = s->head->next;
    s->size--;
    
    return data;
}

//purpose: returns true if stack is empty, false otherwise.
//return value: boolean to indicate if empty.
int stack_is_empty(stack* s){
    return s->size == 0;
}

//purpose: returns the number of elements in the stack
//return: number of elements in the stack
int stack_size(stack* s){
    return s->size;
}