#include <stdio.h>
#include "reports.h"

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

void reportsMenu(const Employee employees[], int employeeCount,
                const Budget budgets[], int budgetCount,
                const Supplier suppliers[], int supplierCount,
                const Asset assets[], int assetCount) {
    int choice;
    do {
        printf("\n================ REPORTS ================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n");
        printf("=========================================\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: employeeReport(employees, employeeCount); break;
            case 2: budgetReport(budgets, budgetCount); break;
            case 3: supplierReport(suppliers, supplierCount); break;
            case 4: assetReport(assets, assetCount); break;
            case 5: break;
            default: printf("Invalid choice. Please select 1 to 5.\n");
        }
    } while (choice != 5);
}

void employeeReport(const Employee employees[], int count) {
    if (count == 0) {
        printf("No employees available for the report.\n");
        return;
    }

    double total = 0.0;
    double highest = calculateSalary(&employees[0]);
    double lowest = calculateSalary(&employees[0]);

    for (int i = 0; i < count; i++) {
        double salary = calculateSalary(&employees[i]);
        total += salary;
        if (salary > highest) highest = salary;
        if (salary < lowest) lowest = salary;
    }

    printf("\n=============== EMPLOYEE REPORT ===============\n");
    printf("Total Employees : %d\n", count);
    printf("Average Salary  : N$ %.2f\n", total / count);
    printf("Highest Salary  : N$ %.2f\n", highest);
    printf("Lowest Salary   : N$ %.2f\n", lowest);
}

void budgetReport(const Budget budgets[], int count) {
    if (count == 0) {
        printf("No budgets available for the report.\n");
        return;
    }

    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    int exceeded = 0;

    for (int i = 0; i < count; i++) {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
        if (!isWithinBudget(&budgets[i])) exceeded++;
    }

    printf("\n================ BUDGET REPORT ================\n");
    printf("Total Allocated Budget : N$ %.2f\n", totalAllocated);
    printf("Total Expenditure      : N$ %.2f\n", totalExpenditure);
    printf("Remaining Budget       : N$ %.2f\n", totalAllocated - totalExpenditure);
    printf("Departments Exceeding  : %d\n", exceeded);
    displayExceededBudgets(budgets, count);
}

void supplierReport(const Supplier suppliers[], int count) {
    printf("\n=============== SUPPLIER REPORT ===============\n");
    if (count == 0) {
        printf("No suppliers are registered.\n");
        return;
    }
    printf("Total Suppliers: %d\n\n", count);
    displaySuppliers(suppliers, count);
}

void assetReport(const Asset assets[], int count) {
    printf("\n================ ASSET REPORT =================\n");
    if (count == 0) {
        printf("No assets are registered.\n");
        return;
    }
    printf("Total Assets: %d\n\n", count);
    displayAssets(assets, count);
}
