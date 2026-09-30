#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100
#define NAME_LEN 100
#define DEPT_LEN 80

typedef struct {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double otherAllowance;
} Employee;

void employeeMenu(Employee employees[], int *count);
void addEmployee(Employee employees[], int *count);
void displayEmployees(const Employee employees[], int count);
void searchEmployee(const Employee employees[], int count);
double calculateSalary(const Employee *employee);
void displayEmployee(const Employee *employee);

#endif
