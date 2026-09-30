#include <stdio.h>
#include <string.h>
#include "employees.h"

static void readLine(const char *prompt, char *value, size_t size) {
    do {
        printf("%s", prompt);
        if (fgets(value, (int)size, stdin) == NULL) {
            value[0] = '\0';
            return;
        }
        value[strcspn(value, "\n")] = '\0';
        if (strlen(value) == 0) {
            printf("Input cannot be empty. Please try again.\n");
        }
    } while (strlen(value) == 0);
}

static int readInt(const char *prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            while (getchar() != '\n') { }
            return value;
        }
        printf("Invalid number. Please try again.\n");
        while (getchar() != '\n') { }
    }
}

static double readNonNegativeDouble(const char *prompt) {
    double value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &value) == 1 && value >= 0) {
            while (getchar() != '\n') { }
            return value;
        }
        printf("Invalid amount. Enter a value of 0 or greater.\n");
        while (getchar() != '\n') { }
    }
}

void employeeMenu(Employee employees[], int *count) {
    int choice;
    do {
        printf("\n========== EMPLOYEE MANAGEMENT ==========\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search for Employee\n");
        printf("4. Return to Main Menu\n");
        printf("=========================================\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addEmployee(employees, count); break;
            case 2: displayEmployees(employees, *count); break;
            case 3: searchEmployee(employees, *count); break;
            case 4: break;
            default: printf("Invalid choice. Please select 1 to 4.\n");
        }
    } while (choice != 4);
}

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee storage is full.\n");
        return;
    }

    Employee *employee = &employees[*count];
    int id = readInt("Enter employee ID: ");

    for (int i = 0; i < *count; i++) {
        if (employees[i].id == id) {
            printf("Employee ID already exists. Employee was not added.\n");
            return;
        }
    }

    employee->id = id;
    readLine("Enter employee name: ", employee->name, NAME_LEN);
    readLine("Enter department: ", employee->department, DEPT_LEN);
    employee->basicSalary = readNonNegativeDouble("Enter basic salary (N$): ");
    employee->housingAllowance = readNonNegativeDouble("Enter housing allowance (N$): ");
    employee->transportAllowance = readNonNegativeDouble("Enter transport allowance (N$): ");
    employee->otherAllowance = readNonNegativeDouble("Enter other allowance (N$): ");

    (*count)++;
    printf("Employee added successfully.\n");
}

double calculateSalary(const Employee *employee) {
    return employee->basicSalary + employee->housingAllowance +
           employee->transportAllowance + employee->otherAllowance;
}

void displayEmployee(const Employee *employee) {
    printf("\nEmployee ID       : %d\n", employee->id);
    printf("Name              : %s\n", employee->name);
    printf("Department        : %s\n", employee->department);
    printf("Basic Salary      : N$ %.2f\n", employee->basicSalary);
    printf("Housing Allowance : N$ %.2f\n", employee->housingAllowance);
    printf("Transport Allow.  : N$ %.2f\n", employee->transportAllowance);
    printf("Other Allowance   : N$ %.2f\n", employee->otherAllowance);
    printf("Total Salary      : N$ %.2f\n", calculateSalary(employee));
}

void displayEmployees(const Employee employees[], int count) {
    if (count == 0) {
        printf("No employees have been registered.\n");
        return;
    }

    printf("\n=============== EMPLOYEE LIST ===============\n");
    for (int i = 0; i < count; i++) {
        displayEmployee(&employees[i]);
        printf("----------------------------------------------\n");
    }
}

void searchEmployee(const Employee employees[], int count) {
    if (count == 0) {
        printf("No employees have been registered.\n");
        return;
    }

    int id = readInt("Enter employee ID to search: ");
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Employee found.\n");
            displayEmployee(&employees[i]);
            return;
        }
    }
    printf("Employee with ID %d was not found.\n", id);
}
