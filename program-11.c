/* Program to find the determinant of a matrix
   Daya Mathew
   29 July 2025
*/

#include <stdio.h>

int determinant2x2(int a[2][2]) 
{
    return (a[0][0]*a[1][1] - a[0][1]*a[1][0]);
}

int determinant3x3(int a[3][3])
 {
    int det;
    det = a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
        - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
        + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
    return det;
}

int main() 
{
    int choice,i,j;
    printf("Find Determinant of:\n1. 2x2 Matrix\n2. 3x3 Matrix\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
	 {
        int a[2][2];
        printf("Enter elements of 2x2 matrix:\n");
        for (i = 0; i < 2; i++)
            for ( j = 0; j < 2; j++)
                scanf("%d", &a[i][j]);

        int det = determinant2x2(a);
        printf("Determinant = %d\n", det);
    }
    else if (choice == 2)
	 {
        int a[3][3];
        printf("Enter elements of 3x3 matrix:\n");
        for ( i = 0; i < 3; i++)
            for ( j = 0; j < 3; j++)
                scanf("%d", &a[i][j]);

        int det = determinant3x3(a);
        printf("Determinant = %d\n", det);
    }
    else
	 {
        printf("Invalid choice\n");
    }
}
