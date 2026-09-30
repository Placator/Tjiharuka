#include <stdio.h>
#include <string.h>
#include "assets.h"

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

void assetMenu(Asset assets[], int *count) {
    int choice;
    do {
        printf("\n=========== ASSET MANAGEMENT ============\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Return to Main Menu\n");
        printf("=========================================\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addAsset(assets, count); break;
            case 2: displayAssets(assets, *count); break;
            case 3: searchAsset(assets, *count); break;
            case 4: break;
            default: printf("Invalid choice. Please select 1 to 4.\n");
        }
    } while (choice != 4);
}

void addAsset(Asset assets[], int *count) {
    if (*count >= MAX_ASSETS) {
        printf("Asset storage is full.\n");
        return;
    }

    Asset *asset = &assets[*count];
    int id = readInt("Enter asset ID: ");

    for (int i = 0; i < *count; i++) {
        if (assets[i].id == id) {
            printf("Asset ID already exists. Asset was not added.\n");
            return;
        }
    }

    asset->id = id;
    readLine("Enter asset name: ", asset->name, NAME_LEN);
    readLine("Enter asset type: ", asset->type, TYPE_LEN);
    asset->purchaseValue = readNonNegativeDouble("Enter purchase value (N$): ");
    readLine("Enter department: ", asset->department, DEPT_LEN);
    readLine("Enter condition: ", asset->condition, CONDITION_LEN);

    (*count)++;
    printf("Asset added successfully.\n");
}

void displayAssets(const Asset assets[], int count) {
    if (count == 0) {
        printf("No assets have been registered.\n");
        return;
    }

    printf("\n================ ASSET REGISTER ================\n");
    for (int i = 0; i < count; i++) {
        printf("Asset ID       : %d\n", assets[i].id);
        printf("Asset Name     : %s\n", assets[i].name);
        printf("Asset Type     : %s\n", assets[i].type);
        printf("Purchase Value : N$ %.2f\n", assets[i].purchaseValue);
        printf("Department     : %s\n", assets[i].department);
        printf("Condition      : %s\n", assets[i].condition);
        printf("------------------------------------------------\n");
    }
}

void searchAsset(const Asset assets[], int count) {
    if (count == 0) {
        printf("No assets have been registered.\n");
        return;
    }

    int id = readInt("Enter asset ID to search: ");
    for (int i = 0; i < count; i++) {
        if (assets[i].id == id) {
            printf("Asset found.\n");
            printf("Asset ID       : %d\n", assets[i].id);
            printf("Asset Name     : %s\n", assets[i].name);
            printf("Asset Type     : %s\n", assets[i].type);
            printf("Purchase Value : N$ %.2f\n", assets[i].purchaseValue);
            printf("Department     : %s\n", assets[i].department);
            printf("Condition      : %s\n", assets[i].condition);
            return;
        }
    }
    printf("Asset with ID %d was not found.\n", id);
}
