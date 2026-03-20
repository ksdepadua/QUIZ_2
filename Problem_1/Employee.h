#include <stdio.h>
#include <stddef.h>

typedef struct {
    long number;
    char *name; // pointer to string
    char *phone; // pointer to string
    double salary;
} Employee, *PtrToEmployee;
// *PtrToEmployee = Pointer to struct Employee

typedef const Employee *PtrToConstEmployee;