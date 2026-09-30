#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100
#define NAME_LEN 100
#define TYPE_LEN 60
#define DEPT_LEN 80
#define CONDITION_LEN 40

typedef struct {
    int id;
    char name[NAME_LEN];
    char type[TYPE_LEN];
    double purchaseValue;
    char department[DEPT_LEN];
    char condition[CONDITION_LEN];
} Asset;

void assetMenu(Asset assets[], int *count);
void addAsset(Asset assets[], int *count);
void displayAssets(const Asset assets[], int count);
void searchAsset(const Asset assets[], int count);

#endif
