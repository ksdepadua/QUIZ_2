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
#define ARR_SIZE 36 // INT_SIZE * 9
#define ROW_SIZE 12 // INT_SIZE * 3
#define COL_SIZE 12 // INT_SIZE * 3

enum returnVal{false, true};

/* Write a function that accepts a two-dimensional array as an argument and determines whether the array is a Lo Shu Magic Square */
// row1Sum = [0][0] + [0][1] + [0][2]
// row2Sum = [1][0] + [1][1] + [1][2]
// row3Sum = [3][0] + [3][1] + [3][2]
// col1Sum = [0][0] + [1][0] + [2][0]
// col2Sum = [0][1] + [1][1] + [2][1]
// col3Sum = [0][2] + [1][2] + [2][2]
// diag1Sum = [0][0] + [1][1] + [2][2]
// diag2Sum = [0][2] + [1][1] + [2][0]
// If any of the sums aren't 15, immediately return false.
const int checkLoShuMagicSquare(int *arr) {
    int sum = 0;
    int * const start = arr;    // Const pointer for arr to return to
    int i;

    // Check row sums
    for(i = 0; i < 9; i++)
    {
        sum += *arr;
        arr++;

        if(i % 3 == 2)  // Last element of the row was added
        {
            if(sum != 15) { return false; }
            sum = 0;
        }
    }

    arr = start; // Reset pointer

    // Check column sums
    for(i = 0; i < 9; i++)
    {
        sum += *arr;
        arr += 3;

        if(i % 3 == 2)
        {
            if(sum != 15) { return false; }
            sum = 0;
            if(i != 8)
                arr -= 8;   // Points to next column
        }
    }

    arr = start; // Reset pointer

    // Check diagonal sums
    // (Top left to bottom right)
    for(i = 0; i < 3; i++)
    {
        sum += *arr;
        arr += 4;
    }
    if(sum != 15) { return false; }

    sum = 0;
    arr = start; // Reset pointer
    arr += 2;   // Set to top right

    // (Top right to bottom left)
    for(i = 0; i < 3; i++)
    {
        sum += *arr;
        arr += 2;
    }
    if(sum != 15) { return false; }
}


/* Write a function that'll populate a 2D array w/ random numbers 1-9 until a Lo Shu Magic Square is generated (NO NUMBER SHOULD REPEAT) */
// Initially populate
// Check if it's a Lo Shu Magic Square
// If it's not, keep populating until it is a Lo Shu Magic Square
// Print total number of squares generated
// Print square as
//  [a b c]
//  [d e f]
//  [g h i]
static void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize ( int arr[], int n )
{
    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand ( time(NULL) );

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

void createLoShuMagicSquare() {
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2d[3][3];
    map1dTo2d(arr, arr2d);
    //int arr[3][3] = {2, 7, 6, 9, 5, 1, 4, 3, 8};
    int count = 0;

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
    printf("Squares generated and tested (include the success): %d", count);
}