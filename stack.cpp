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

// each cpp includes ONLY it's header directly!
#include "stack.h"

/*
 * write all your stack methods here
 */

Stack::Stack() {
    top = -1; // signifies stack is empty
}
Stack::~Stack() {
    for (int i=0; i<top+1; i++) // top+1 bc top is an index
        delete stack[i]; // deletes data @ ptr location, not ptr
}

bool Stack::isEmpty(){
    return false;
}

bool Stack::peek(Data* peekPtr) {
    return false;
} // end peek()

bool Stack::pop(Data* popPtr){
  return false;
} // end pop()

bool Stack::push(int pushedID, string pushedData){
    return false;
} // end push()

