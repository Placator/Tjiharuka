#include <stdio.h>
#include <string.h>
#include "suppliers.h"

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

void supplierMenu(Supplier suppliers[], int *count) {
    int choice;
    do {
        printf("\n========== SUPPLIER MANAGEMENT =========\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Return to Main Menu\n");
        printf("========================================\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addSupplier(suppliers, count); break;
            case 2: displaySuppliers(suppliers, *count); break;
            case 3: searchSupplier(suppliers, *count); break;
            case 4: break;
            default: printf("Invalid choice. Please select 1 to 4.\n");
        }
    } while (choice != 4);
}

void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_SUPPLIERS) {
        printf("Supplier storage is full.\n");
        return;
    }

    Supplier *supplier = &suppliers[*count];
    int id = readInt("Enter supplier ID: ");

    for (int i = 0; i < *count; i++) {
        if (suppliers[i].id == id) {
            printf("Supplier ID already exists. Supplier was not added.\n");
            return;
        }
    }

    supplier->id = id;
    readLine("Enter supplier name: ", supplier->name, NAME_LEN);
    readLine("Enter email: ", supplier->email, EMAIL_LEN);
    readLine("Enter telephone number: ", supplier->telephone, PHONE_LEN);
    readLine("Enter town/location: ", supplier->location, LOCATION_LEN);

    (*count)++;
    printf("Supplier added successfully.\n");
}

void displaySuppliers(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("No suppliers have been registered.\n");
        return;
    }

    printf("\n================ SUPPLIER LIST ================\n");
    for (int i = 0; i < count; i++) {
        printf("Supplier ID : %d\n", suppliers[i].id);
        printf("Name        : %s\n", suppliers[i].name);
        printf("Email       : %s\n", suppliers[i].email);
        printf("Telephone   : %s\n", suppliers[i].telephone);
        printf("Location    : %s\n", suppliers[i].location);
        printf("------------------------------------------------\n");
    }
}

void searchSupplier(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("No suppliers have been registered.\n");
        return;
    }

    char searchName[NAME_LEN];
    readLine("Enter supplier name to search: ", searchName, NAME_LEN);

    for (int i = 0; i < count; i++) {
        if (strcmp(suppliers[i].name, searchName) == 0) {
            printf("Supplier found.\n");
            printf("Supplier ID : %d\n", suppliers[i].id);
            printf("Name        : %s\n", suppliers[i].name);
            printf("Email       : %s\n", suppliers[i].email);
            printf("Telephone   : %s\n", suppliers[i].telephone);
            printf("Location    : %s\n", suppliers[i].location);
            return;
        }
    }
    printf("Supplier '%s' was not found.\n", searchName);
}
