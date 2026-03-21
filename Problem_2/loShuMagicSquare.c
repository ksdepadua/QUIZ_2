/*
Create a program by simulating a magic square using a two-dimensional array. Write a
function that accepts a two-dimensional array as an argument and determines whether the
array is a Lo Shu Magic Square. Test the function in a program.
1) Create the program and test with an array that is a Lo Shu Magic Square and test
where it is not. The array’s can be defined in your main and should not need to be
input from the user.
2) Create and populate a two-dimensional array with random numbers from 1-9. Recall
no number should repeat when populating the array. Then check if it is a Lo Shu
Magic Square. Put this random number placement in a loop until you do get a Lo Shu
Magic Square. Print two things:
a. The total number of squares generated and tested before success, the count.
b. Print the square and show the placement of values in the following format:
    [a b c]
    [d e f]
    [g h i]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_SIZE 4
#define ARR_SIZE 9
#define NUM_ROWS 3
#define NUM_COLS 3
#define DIAG_SIZE 3

enum returnVal{false, true};

// Calculates sums of rows
// Returns targetSum if all rows match, returns false (0) if rows don't match
static const int checkRowSums(const int *arr) {
    int currSum = 0, target = -1;
    int *arrPtr = arr;

    for(int i = 0; i < ARR_SIZE; i++)
    {
        currSum += *arrPtr;
        arrPtr++;

        if(i % NUM_COLS == 2) {
            if(target == -1) { target = currSum; }
            else if(currSum != target) { return false; }
            currSum = 0;
        }
    }

    return target;
}

// Calculates sums of rows
// Returns targetSum if all cols match, returns false (0) if cols don't match
static const int checkColSums(const int *arr, const int target) {
    int currSum = 0;
    int *arrPtr = arr;

    for(int i = 0; i < ARR_SIZE; i++)
    {
        currSum += *arrPtr;
        arrPtr += NUM_ROWS;

        if(i % NUM_ROWS == 2) {
            if(currSum != target) { return false; }
            currSum = 0;
            if(i != 8) { arrPtr -= 8; } //Points to next column
        }
    }

    return target;
}

const int checkLoShuMagicSquare(int *arr) {
    int target;
    int temp = 0;
    int * const start = arr;    // Const pointer for arr to return to
    int i;

    // Checks if middle value is 5
    if(*(arr + 4) != 5) { return false; }

    arr = start;

    // Check row sums
    target = checkRowSums(arr);
    if(target == false) { return false; }

    // Check column sums
    target = checkColSums(arr, target);
    if(target == false) { return false; }

    // Check diagonal sums
    // (Top left to bottom right)
    for(i = 0; i < DIAG_SIZE; i++)
    {
        temp += *arr;
        arr += 4;
    }
    if(temp != target) { return false; }

    temp = 0;
    arr = start; // Reset pointer
    arr += 2;    // Set to top right

    // (Top right to bottom left)
    for(i = 0; i < DIAG_SIZE; i++)
    {
        temp += *arr;
        arr += 2;
    }
    if(temp != target) { return false; }
}

// Helper functions swap(), randomize() and map1dTo2d() for createLoShuMagicSquare()
static void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void randomize ( int *arr, int n )
{
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);

        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }
}

static void map1dTo2d(int arr1[9], int arr2[3][3]) {
    for(int i = 0; i < 9; i++) {
        int row = i / 3;
        int col = i % 3;

        arr2[row][col] = arr1[i];
    }
}

// Note: At max, you can have 9! different squares (362,880)
void createLoShuMagicSquare() {
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2d[3][3];
    map1dTo2d(arr, arr2d);
    int count = 0;
    srand(time(0));

    do
    {
        if(checkLoShuMagicSquare((&arr2d[0][0])))
            break;
        randomize(arr, 9);
        map1dTo2d(arr, arr2d);
        count++;
    } while (true);

    printf("Lo Shu Magic Square found: \n");
    printf("[%d %d %d]\n", arr2d[0][0], arr2d[0][1], arr2d[0][2]);
    printf("[%d %d %d]\n", arr2d[1][0], arr2d[1][1], arr2d[1][2]);
    printf("[%d %d %d]\n", arr2d[2][0], arr2d[2][1], arr2d[2][2]);
    printf("Squares generated and tested (includes the success): %d", count);
}