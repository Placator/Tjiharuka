#include <stdio.h>
#include <string.h>
#include "budget.h"

static void readLine(const char *prompt, char *value, size_t size) {
    do {
        printf("%s", prompt);
        if (fgets(value, (int)size, stdin) == NULL) {
            value[0] = '\0';
            return;
        }
        value[strcspn(value, "\n")] = '\0';
        if (strlen(value) == 0) printf("Input cannot be empty.\n");
    } while (strlen(value) == 0);
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

void budgetMenu(Budget budgets[], int *count) {
    int choice;
    do {
        printf("\n=========== BUDGET MANAGEMENT ===========\n");
        printf("1. Add Department Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Display Departments Exceeding Budget\n");
        printf("4. Return to Main Menu\n");
        printf("=========================================\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addBudget(budgets, count); break;
            case 2: displayBudgets(budgets, *count); break;
            case 3: displayExceededBudgets(budgets, *count); break;
            case 4: break;
            default: printf("Invalid choice. Please select 1 to 4.\n");
        }
    } while (choice != 4);
}

void addBudget(Budget budgets[], int *count) {
    if (*count >= MAX_BUDGETS) {
        printf("Budget storage is full.\n");
        return;
    }

    Budget *budget = &budgets[*count];
    readLine("Enter department: ", budget->department, DEPT_LEN);
    budget->allocatedBudget = readNonNegativeDouble("Enter allocated budget (N$): ");
    budget->expenditure = readNonNegativeDouble("Enter expenditure (N$): ");

    (*count)++;
    printf("Budget information added successfully.\n");
}

double calculateRemainingBudget(const Budget *budget) {
    return budget->allocatedBudget - budget->expenditure;
}

int isWithinBudget(const Budget *budget) {
    return budget->expenditure <= budget->allocatedBudget;
}

void displayBudgets(const Budget budgets[], int count) {
    if (count == 0) {
        printf("No budget information has been registered.\n");
        return;
    }

    printf("\n================ BUDGET REPORT ================\n");
    for (int i = 0; i < count; i++) {
        double remaining = calculateRemainingBudget(&budgets[i]);
        printf("Department       : %s\n", budgets[i].department);
        printf("Allocated Budget : N$ %.2f\n", budgets[i].allocatedBudget);
        printf("Expenditure      : N$ %.2f\n", budgets[i].expenditure);
        printf("Remaining Budget : N$ %.2f\n", remaining);
        printf("Status           : %s\n", isWithinBudget(&budgets[i]) ? "WITHIN BUDGET" : "EXCEEDED BUDGET");
        printf("------------------------------------------------\n");
    }
}

void displayExceededBudgets(const Budget budgets[], int count) {
    int found = 0;
    printf("\n======= DEPARTMENTS EXCEEDING BUDGET =======\n");
    for (int i = 0; i < count; i++) {
        if (!isWithinBudget(&budgets[i])) {
            printf("%s: Exceeded by N$ %.2f\n", budgets[i].department,
                   budgets[i].expenditure - budgets[i].allocatedBudget);
            found = 1;
        }
    }
    if (!found) printf("No department has exceeded its allocated budget.\n");
}
