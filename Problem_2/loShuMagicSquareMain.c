// Test a given 2D array that is a Lo Shu Magic Square (checkLoShuMagicSquare())
// Test a given 2d array that is NOT a Lo Shu Magic Square (checkLoShuMagicSquare())

// Run generateLoShuMagicSquare()
#include <stdio.h>

int main(void) {
    //Defined in loShuMagicSquare.c
    int checkLoShuMagicSquare(const int arr[3][3]);
    void createLoShuMagicSquare();

    int test1[3][3] = {{4, 9, 2}, 
                      {3, 5, 7}, 
                      {8, 1, 6}};
    int test2[3][3] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};
    int test3[3][3] = {2, 7, 6, 9, 5, 1, 4, 3, 8};

    if(checkLoShuMagicSquare(test1))
        printf("Array of {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}} is a Lo Shu Magic Square!\n");
    else
        printf("Array of {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}} is not a Lo Shu Magic Square.\n");

    if(checkLoShuMagicSquare(test2))
        printf("Array of {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}} is a Lo Shu Magic Square!\n");
    else
        printf("Array of {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}} is not a Lo Shu Magic Square.\n");
    if(checkLoShuMagicSquare(test3))
        printf("Array test3 is a Lo Shu Magic Square!\n");
    else
        printf("Array test3 is not a Lo Shu Magic Square.\n");

    createLoShuMagicSquare();
}