/* Program to insert,search delete and sort elements in an array
   Daya Mathew
   27 July 2025
*/
#include <stdio.h>

void insert(int a[], int *n) 
{
    int x;
    if (*n >= 100)
	 {
        printf("Array is full!\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &x);
    a[*n] = x;
    (*n)++;
    printf("Inserted.\n");
}

void search(int a[], int n) 
{
    int x, i, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &x);
    for (i = 0; i < n; i++)
	 {
        if (a[i] == x) 
		{
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Element not found\n");
}

void deleteElement(int a[], int *n) 
{
    int x, i, j, found = 0;
    printf("Enter element to delete: ");
    scanf("%d", &x);
    for (i = 0; i < *n; i++)
	 {
        if (a[i] == x) 
		{
            for (j = i; j < *n - 1; j++)
			 {
                a[j] = a[j + 1];
            }
            (*n)--;
            found = 1;
            printf("Deleted.\n");
            break;
        }
    }
    if (!found)
        printf("Element not found\n");
}

void sort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("Array sorted.\n");
}

void display(int a[], int n) 
{
    if (n == 0)
	 {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
 {
    int a[100], n = 0, ch;

    do 
	{
        printf("\n1.Insert  2.Search  3.Delete  4.Sort  5.Display  6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) 
		{
            case 1: insert(a, &n); break;
            case 2: search(a, n); break;
            case 3: deleteElement(a, &n); break;
            case 4: sort(a, n); break;
            case 5: display(a, n); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (ch != 6);

}

