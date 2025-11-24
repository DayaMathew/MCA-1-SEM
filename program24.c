/* Program to multiply two sparse matrices using triplet form
   @Daya Mathew
   03-10-2025
*/

#include <stdio.h>

int a[5][5], b[20][3];   // Matrix A and its triplet form
int c[5][5], d[20][3];   // Matrix B and its triplet form
int res[40][3];           // Result triplet form
int i, j, k;

// Function to convert normal matrix into triplet form
int tripletform(int mat[5][5], int tri[20][3], int n, int m) {
    int count = 0, k = 1;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(mat[i][j] != 0) {
                tri[k][0] = i;
                tri[k][1] = j;
                tri[k][2] = mat[i][j];
                k++;
                count++;
            }
        }
    }

    tri[0][0] = n;
    tri[0][1] = m;
    tri[0][2] = count;

    return (count + 1);  // number of rows in triplet matrix
}

// Function to print triplet form
void printTriplet(int tri[20][3]) {
    int k;
    printf("\nRow Col Val\n");
    for(k = 0; k <= tri[0][2]; k++) {
        printf("%d   %d   %d\n", tri[k][0], tri[k][1], tri[k][2]);
    }
}

// Function to multiply two sparse matrices
void multiplyTriplet(int t1[20][3], int t2[20][3], int res[40][3]) {
    int i, j, k = 1, n1 = t1[0][0], m1 = t1[0][1], n2 = t2[0][0], m2 = t2[0][1];

    // Check if multiplication is possible
    if(m1 != n2) {
        printf("\nMultiplication not possible (inner dimensions do not match).\n");
        return;
    }

    res[0][0] = n1;
    res[0][1] = m2;
    res[0][2] = 0; // will increment as we find non-zero elements

    for(i = 1; i <= t1[0][2]; i++) {
        for(j = 1; j <= t2[0][2]; j++) {
            if(t1[i][1] == t2[j][0]) { // column of A matches row of B
                // Check if this position already exists in result
                int found = 0;
                int p;
                for( p = 1; p <= res[0][2]; p++) {
                    if(res[p][0] == t1[i][0] && res[p][1] == t2[j][1]) {
                        res[p][2] += t1[i][2] * t2[j][2];
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    res[k][0] = t1[i][0];
                    res[k][1] = t2[j][1];
                    res[k][2] = t1[i][2] * t2[j][2];
                    k++;
                    res[0][2]++; // increment non-zero count
                }
            }
        }
    }
}

int main() {
    int n1, m1, n2, m2;
    int k1, k2;

    // Input dimensions for Matrix A
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d%d", &n1, &m1);

    // Input dimensions for Matrix B
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d%d", &n2, &m2);

    // Check if multiplication is possible
    if(m1 != n2) {
        printf("Matrix multiplication not possible (inner dimensions do not match).\n");
        return 0;
    }

    // Input elements of Matrix A
    printf("Enter elements of Matrix A:\n");
    for(i = 0; i < n1; i++)
        for(j = 0; j < m1; j++)
            scanf("%d", &a[i][j]);

    // Input elements of Matrix B
    printf("Enter elements of Matrix B:\n");
    for(i = 0; i < n2; i++)
        for(j = 0; j < m2; j++)
            scanf("%d", &c[i][j]);

    // Convert to triplet form
    k1 = tripletform(a, b, n1, m1);
    k2 = tripletform(c, d, n2, m2);

    // Print triplet forms
    printf("\nTriplet form of Matrix A:\n");
    printTriplet(b);

    printf("\nTriplet form of Matrix B:\n");
    printTriplet(d);

    // Multiply triplets
    multiplyTriplet(b, d, res);

    // Print result
    printf("\nResultant Triplet Matrix after Multiplication:\n");
    printTriplet(res);

    return 0;
}

