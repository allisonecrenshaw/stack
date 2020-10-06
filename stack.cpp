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
    bool empty = false;
    if (top<0) {empty=true;};
    return empty;
}

bool Stack::peek(Data* peekPtr) {
    bool ok = false;
    if (isEmpty()) { // if stack is empty, give dummy vals
        peekPtr->id = -1;
        peekPtr->information = "";
    }
    else { // assign values from top
        ok = true;
        peekPtr->id = stack[top]->id;
        peekPtr->information = stack[top]->information;
    }
    return ok;
} // end peek()

bool Stack::pop(Data* popPtr){
    bool ok = false;
    if (isEmpty()) { // if stack is empty, give dummy vals
        popPtr->id = -1;
        popPtr->information = "";
    }
    else { // assign values from top
        ok = true;
        popPtr->id = stack[top]->id;
        popPtr->information = stack[top]->information;
    }
    // delete allocated memory and decrement counter to reflect pop
    delete stack[top--];
    return ok;
} // end pop()

bool Stack::push(int pushedID, string pushedData){
    return false;
} // end push()

