// Compile using the following commands: 
//  gcc employeeMain.c employeeTable.c employeeOne.c
//  gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>

#include "employee.h"

int main(void) {
    // Defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    // Defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;

    // Example not found (Employee ID)
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID 1045 is NOT found in the record\n");

    // Example found (Employee Name)
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // Example found (Phone Number)
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");

    if (matchPtr != NULL)
        printf("Employee Phone 714-555-2749 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Phone 714-555-2749 is NOT found in the record\n");

    // Example not found (Phone Number)
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "111-111-1111");

    if (matchPtr != NULL)
        printf("Employee Phone 111-111-1111 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Phone 111-111-1111 is NOT found in the record\n");

    // Example found (Salary)
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78);

    if (matchPtr != NULL)
        printf("Employee with Salary of 8.78 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with Salary of 8.78 is NOT found in the record\n");

    // Example not found (Salary)
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 5.71);

    if (matchPtr != NULL)
        printf("Employee with Salary of 5.71 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with Salary of 5.71 is NOT found in the record\n");

    return EXIT_SUCCESS;
}
