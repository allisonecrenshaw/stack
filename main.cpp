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
    char *information[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        information[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, information, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, information, number_test_cases);

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
    cout << endl;
    cout << "Pushing first Data onto stack..." << endl;
    pushSuccessful = stack.push(ids[0], information[0]);
    stack.pushTest(pushSuccessful);
    // call peek and pop to see if they match
    cout << "Peek and pop should show just-pushed data..." << endl;
    peekSuccessful = stack.peek(&peekData);
    stack.peekPopTest("Peek", peekSuccessful, &peekData);
    popSuccessful = stack.pop(&popData);
    stack.peekPopTest("Pop", popSuccessful, &popData);

    cout << endl;
    // call peek and pop again to see that it's empty again
    cout << "Calling peek and pop again, should fail (stack empty)..." << endl;
    peekSuccessful = stack.peek(&peekData);
    stack.peekPopTest("Peek", peekSuccessful, &peekData);
    Data newPopData;
    popSuccessful = stack.pop(&newPopData);
    stack.peekPopTest("Pop", popSuccessful, &newPopData);

    cout << endl;
    cout << lineBreak << endl;
    cout << "Testing with set number of cases." << endl;
    cout << lineBreak << endl;

    // call push, pop, and peek enough times to overflow
    int overflow = 11;
    string myData[] = {"one", "two", "three", "four", "five", "six",
                       "seven", "eight", "nine", "ten", "eleven"};

    for (int set=1; set<=overflow; set++) {
        // <=overflow allows attempt to push when stack full
        cout << "Calling push, peek, pop sequence "
             << set << " times: " << endl;
        cout << "PUSHES:" << endl;
        for (int i=0; i<set; i++) {
            pushSuccessful = stack.push(i+1, myData[i]);
            stack.pushTest(pushSuccessful);
        }
        // call peek and pop one extra time (index<=set) to test when empty
        cout << endl << "PEEKS AND POPS:" << endl;
        for (int index=0; index<=set; index++) {
            peekSuccessful = stack.peek(&peekData);
            stack.peekPopTest("Peek", peekSuccessful, &peekData);
            popSuccessful = stack.pop(&popData);
            stack.peekPopTest("Pop", popSuccessful, &popData);
        }
        cout << endl;
    } // end for loop




    cout << endl;
    cout << lineBreak << endl;
    cout << "Starting testing with random numbers of pushes and pops." << endl;
    cout << lineBreak << endl;

    // call push and peek random number of times
    int numOfTests = 10; // five sets of random tests
    int numOfPushes, numOfPops;

    cout << "Calling push, peek, pop sequence 5x w/ random num of pushes, pops: " << endl;
    for (int i=0; i<numOfTests; i++) {
        numOfPushes = (rand() % number_test_cases)+1;
        numOfPops = (rand() % number_test_cases)+1;

        cout << numOfPushes << " PUSHES:" << endl;
        for (int j=0; j<numOfPushes; j++) {
            pushSuccessful = stack.push(ids[j], information[j]);
            stack.pushTest(pushSuccessful);
        } // end loop of pushes
        cout << endl;

        cout << numOfPops << " PEEKS AND POPS:" << endl;
        for (int j=0; j<numOfPops; j++) {
            peekSuccessful = stack.peek(&peekData);
            stack.peekPopTest("Peek", peekSuccessful, &peekData);
            popSuccessful = stack.pop(&popData);
            stack.peekPopTest("Pop", popSuccessful, &popData);
        }
        cout << endl;
    } // end outer for loop


    // message to signal end of program
    cout << lineBreak << endl;
    cout << "fin." << endl;
    cout << lineBreak << endl;
    return 0;
}
