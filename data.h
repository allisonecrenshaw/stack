/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * DO NOT MODIFY THIS FILE
 */

#ifndef STACKS_DATA_H
#define STACKS_DATA_H

#include <string>
using std::string;

/*
 * Simple data structure to simulate the idea of an ADT which contains
 * an identifier and some kind of information. It's not important how complex
 * or simple this structure is, we only want to simulate the idea of
 * a single structure that contains both an identifier and data.
 */
struct Data {
    int id;
    string information;
};

#endif /* STACKS_DATA_H */
