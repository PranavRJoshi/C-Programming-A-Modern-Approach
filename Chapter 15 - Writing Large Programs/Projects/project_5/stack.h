#ifndef STACK_H 
#define STACK_H

/*
 * make_empty:  makes the stack empty by having top as 0.
*/
void make_empty (void);

/*
 * is_empty:  returns true if top is 0, else false.
*/
bool is_empty (void);

/*
 * is_full: returns true if top is equal to the stack
 *          size, else false.
*/
bool is_full (void);

/*
 * push:  checks if the stack is full or not. If it is
 *        not full, pushes the "item" onto the stack.
*/
void push (int item);

/*
 * pop: checks if the stack is empty or not. If it is
 *      not, the item in the top of the stack is 
 *      popped.
*/
int pop (void);

/*
 * stack_overflow:  indicates that the stack is full.
*/
void stack_overflow (void);

/*
 * stack_underflow: indicates that the stack is empty.
*/
void stack_underflow (void);

#endif 
