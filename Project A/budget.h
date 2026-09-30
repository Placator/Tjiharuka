#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 100
#define DEPT_LEN 80

typedef struct {
    char department[DEPT_LEN];
    double allocatedBudget;
    double expenditure;
} Budget;

void budgetMenu(Budget budgets[], int *count);
void addBudget(Budget budgets[], int *count);
void displayBudgets(const Budget budgets[], int count);
double calculateRemainingBudget(const Budget *budget);
int isWithinBudget(const Budget *budget);
void displayExceededBudgets(const Budget budgets[], int count);

#endif
