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

/* Write a function that'll populate a 2D array w/ random numbers 1-9 until a Lo Shu Magic Square is generated (NO NUMBER SHOULD REPEAT) */
// Initially populate
// Check if it's a Lo Shu Magic Square
// If it's not, keep populating until it is a Lo Shu Magic Square
// Print total number of squares generated
// Print square as
//  [a b c]
//  [d e f]
//  [g h i]