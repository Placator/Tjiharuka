#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100
#define NAME_LEN 100
#define EMAIL_LEN 100
#define PHONE_LEN 30
#define LOCATION_LEN 80

typedef struct {
    int id;
    char name[NAME_LEN];
    char email[EMAIL_LEN];
    char telephone[PHONE_LEN];
    char location[LOCATION_LEN];
} Supplier;

void supplierMenu(Supplier suppliers[], int *count);
void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(const Supplier suppliers[], int count);
void searchSupplier(const Supplier suppliers[], int count);

#endif
