/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
    
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */

    // testing variables
    string lineBreak = "********************************";

    bool empty;
    string isEmptyMsg = "Stack empty.";
    string notEmptyMsg = "Stack not empty.";

    bool peekSuccessful;
    Data peekData;
    bool popSuccessful;
    Data popData;
    bool pushSuccessful;


    // test isEmpty, peek, and pop once each on empty stack
    cout << endl;
    cout << lineBreak << endl;
    cout << "Start testing written by student." << endl;

    cout << lineBreak << endl;
    cout << "Testing isEmpty, peek, and pop on empty stack..." << endl;
    empty = stack.isEmpty();
    if (empty == true)
        cout << isEmptyMsg << endl;
    else
        cout << notEmptyMsg << endl;
    // test peek and pop while stack empty
    peekSuccessful = stack.peek(&peekData);
    stack.peekPopTest("Peek", peekSuccessful, &peekData);
    stack.peekPopTest("Pop", popSuccessful, &peekData);


    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack.
     */

    // test push once, followed by a peek and pop if push is successful
    // call push w/ data then call test to output info
    cout << endl;
    cout << "Pushing first Data onto stack..." << endl;
    pushSuccessful = stack.push(ids[0], data[0]);
    stack.pushTest(pushSuccessful);
    // call peek and pop to see if they match
    cout << "Peek and pop should show just-pushed data..." << endl;
    peekSuccessful = stack.peek(&peekData);
    stack.peekPopTest("Peek", peekSuccessful, &peekData);
    popSuccessful = stack.pop(&popData);
    stack.peekPopTest("Pop", popSuccessful, &popData);

    cout << endl;
    cout << "Next part goes here." << endl;





    return 0;
}
