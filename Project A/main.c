#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

static void displayMainMenu(void) {
    printf("\n==============================================\n");
    printf("      MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("==============================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("==============================================\n");
}

int main(void) {
    Employee employees[MAX_EMPLOYEES];
    Budget budgets[MAX_BUDGETS];
    Supplier suppliers[MAX_SUPPLIERS];
    Asset assets[MAX_ASSETS];

    int employeeCount = 0;
    int budgetCount = 0;
    int supplierCount = 0;
    int assetCount = 0;
    int choice;

    printf("\nWelcome to the Municipal Financial Management System!\n");

    do {
        displayMainMenu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number from 1 to 6.\n");
            while (getchar() != '\n') {
                /* Clear invalid input. */
            }
            continue;
        }
        while (getchar() != '\n') {
            /* Clear remaining input. */
        }

        switch (choice) {
            case 1:
                employeeMenu(employees, &employeeCount);
                break;
            case 2:
                budgetMenu(budgets, &budgetCount);
                break;
            case 3:
                supplierMenu(suppliers, &supplierCount);
                break;
            case 4:
                assetMenu(assets, &assetCount);
                break;
            case 5:
                reportsMenu(employees, employeeCount,
                            budgets, budgetCount,
                            suppliers, supplierCount,
                            assets, assetCount);
                break;
            case 6:
                printf("\nThank you for using the Municipal Financial Management System.\n");
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid menu choice. Please select 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}
