/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * DO NOT MODIFY THIS FILE
 */

#include "functions.h"

/*
 * This function accepts an integer array (ids), a 2D character array, and the
 * 1D size of the arrays (i.e. they are parallel arrays). It then fills the
 * arrays with random integer ids and strings such as 'aaaaaaaaaaaaaaaa' and 
 * 'bbbbbbbbbbbbbbbb', etc. These are passed by reference, so no return is needed.
 */
void make_test_cases(int *ids, char **data, int num_cases) {

    for (int i = 0; i < num_cases; i++) {
        ids[i] = rand() % MAX_ID + 1;
        for (int j = 0; j < BUFFER_SIZE - 1; j++) {
            data[i][j] = 'a' + i;
        }
        data[i][BUFFER_SIZE - 1] = '\0';
    }
}

/*
 * This function accepts an integer array (ids), a 2D character array, and the
 * 1D size of the arrays (i.e. they are parallel arrays). It displays the two
 * arrays. Remember, a 2D array of characters is also a potential 1D array of
 * strings if you load it that way as was done above.
 */
void display_test_cases(int *ids, char **data, int num_cases) {
    cout << "Displaying test cases..." << endl;
    for (int i = 0; i < num_cases; i++) {
        cout << ids[i] << ": " << data[i] << endl;
    }
}
