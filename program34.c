#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure definition for Employee
struct employee {
    int eno;
    char ename[30];
    float esal;
    int dno;
};

// Function to read employee details
void readEmployees(struct employee e[], int n) 
{
	int i;
    for (i = 0; i < n; i++) 
	{	
        printf("\nEnter details of employee %d:\n", i + 1);
        printf("Employee No: ");
        scanf("%d", &e[i].eno);
        printf("Employee Name: ");
        scanf("%s", e[i].ename);
        printf("Employee Salary: ");
        scanf("%f", &e[i].esal);
        printf("Department No: ");
        scanf("%d", &e[i].dno);
    }
}

// Function to display employee details
void displayEmployees(struct employee e[], int n) {
    printf("\n%-10s %-15s %-10s %-10s\n", "Emp No", "Name", "Salary", "Dept No");
    printf("---------------------------------------------\n");
    int i;
    for ( i = 0; i < n; i++) {
        printf("%-10d %-15s %-10.2f %-10d\n", e[i].eno, e[i].ename, e[i].esal, e[i].dno);
    }
}

// a. Function to search employee by number
int searchByNo(struct employee e[], int n, int eno)
{	int i;
    for ( i = 0; i < n; i++) 
	{
        if (e[i].eno == eno)
            return i; // return index if found
    }
    return -1; // not found
}

// b.i. Function to sort employees by name
void sortByName(struct employee e[], int n) 
{
    struct employee temp;
    int i;
    for ( i = 0; i < n - 1; i++) 
	{	int j;
        for ( j = i + 1; j < n; j++) 
		{
            if (strcmp(e[i].ename, e[j].ename) > 0) 
			{
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

// b.ii. Function to sort employees by salary
void sortBySalary(struct employee e[], int n) 
{
    struct employee temp;
    int i;
    for ( i = 0; i < n - 1; i++) 
	{	int j;
        for ( j = i + 1; j < n; j++) 
		{
            if (e[i].esal > e[j].esal)
			{	int j;
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

// c. Function to delete an employee by number
int deleteEmployee(struct employee e[], int n, int eno)
 {
    int pos = searchByNo(e, n, eno);
    if (pos == -1) {
        printf("\nEmployee not found!\n");
        return n; // no change in number of employees
    }
   	int i;
    for ( i = pos; i < n - 1; i++) 
	{	
        e[i] = e[i + 1];
    }
    printf("\nEmployee deleted successfully.\n");
    return n - 1; // one less employee
}

// Main function
int main() {
    struct employee e[MAX];
    int n, choice, eno;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    readEmployees(e, n);

    while (1) {
        printf("\n--- Employee Menu ---\n");
        printf("1. Display all employees\n");
        printf("2. Search employee by number\n");
        printf("3. Sort by Name\n");
        printf("4. Sort by Salary\n");
        printf("5. Delete an employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displayEmployees(e, n);
            break;

        case 2:
            printf("Enter employee number to search: ");
            scanf("%d", &eno);
            int pos = searchByNo(e, n, eno);
            if (pos == -1)
                printf("Employee not found.\n");
            else {
                printf("\nEmployee found:\n");
                printf("Emp No: %d\nName: %s\nSalary: %.2f\nDept No: %d\n",
                       e[pos].eno, e[pos].ename, e[pos].esal, e[pos].dno);
            }
            break;

        case 3:
            sortByName(e, n);
            printf("\nEmployees sorted by Name:\n");
            displayEmployees(e, n);
            break;

        case 4:
            sortBySalary(e, n);
            printf("\nEmployees sorted by Salary:\n");
            displayEmployees(e, n);
            break;

        case 5:
            printf("Enter employee number to delete: ");
            scanf("%d", &eno);
            n = deleteEmployee(e, n, eno);
            break;

        case 6:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

