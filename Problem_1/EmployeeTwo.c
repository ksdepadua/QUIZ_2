#include <string.h>

#include "employee.h"

// Utilizes function pointers to reduce redundant code

/*
*   NOTE: 5 functions have been defined below
*   ptr - points to table to be searched
*   tableSize - size of the table
*   targetPtr - points to value that will be searched for in table
*   functionPtr - points to a comparison function below and will perform the associate check
*/

// What does setting a function to static do???
//  Static functions aren't visible outside of the object file they're compiled into
//  Restricts access to the function; Also helpful if we want to reuse the same function name in other files
//  Reference: https://www.geeksforgeeks.org/c/what-are-static-functions-in-c/
// functionPtr is the address of the function, just use the name
// ()(The second set of parentheses is the arguments of the function call)
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr,
                                        int (*functionPtr)(const void *, PtrToConstEmployee)) {
    PtrToConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++)
    {
        if ((*functionPtr)(targetPtr, ptr) == 0)
            return (PtrToEmployee) ptr;
    }

    return NULL;
}

// functionPtr will point to one of the comparison functions to perform a check
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return * (long *) targetPtr != tableValuePtr->number;
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return strcmp((char *) targetPtr, tableValuePtr->name);
}

// Create compareEmployeePhone()
static int compareEmployeePhone(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return strcmp((char *) targetPtr, tableValuePtr->phone);
}

// Create compareEmployeeSalary()
static int compareEmployeeSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return * (double *) targetPtr != tableValuePtr->salary;
}

// Wrappers
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number) {
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char *name) {
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}

// Create searchEmployeeByPhone()
PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char *phone) {
    return searchEmployeeTable(ptr, size, phone, compareEmployeePhone);
}

// Create searchEmployeeBySalary()
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary) {
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalary);
}