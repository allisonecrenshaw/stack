/*********************
Name: Allison Crenshaw
Coding 04
Purpose: This program creates the structure
 for a stack of Data objects (ADT created by prof).
 Must include extensive testing of functions.
**********************/

/*
 * modify this file as needed to complete the assignment
 */

#ifndef STACK_H
#define STACK_H

/*
 * notice there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#include <iostream>     /* cout, endl */
using std::cout;
using std::endl;

#define STACK_SIZE 10 // do not modify this define

class Stack {

public:

    /* 
     * write all your public method prototypes here
     * this includes you constructor and destructor
     */
    Stack(); // constructor
    ~Stack(); // destructor

    bool isEmpty();
    bool peek(Data*);
    bool pop(Data*);
    bool push(int, string);
    void peekPopTest(string, bool, Data*);
    void pushTest(bool);
    
private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need. do not modify them or add any
    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H