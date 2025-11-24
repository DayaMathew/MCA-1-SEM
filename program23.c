/* Program to add two sparse matrices using triplet form
   @Daya Mathew
   08-09-2025
*/

#include <stdio.h>

int a[5][5], b[20][3];   // Matrix A and its triplet form
int c[5][5], d[20][3];   // Matrix B and its triplet form
int res[40][3];           // Result triplet form
int i, j;

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

// Function to add two triplet matrices
void addTriplet(int t1[20][3], int t2[20][3], int res[40][3]) {
    int i = 1, j = 1, k = 1;

    if(t1[0][0] != t2[0][0] || t1[0][1] != t2[0][1]) {
        printf("\nAddition not possible (different sizes).\n");
        return;
    }

    res[0][0] = t1[0][0];
    res[0][1] = t1[0][1];

    while(i <= t1[0][2] && j <= t2[0][2]) {
        if(t1[i][0] < t2[j][0] || (t1[i][0] == t2[j][0] && t1[i][1] < t2[j][1])) {
            res[k][0] = t1[i][0];
            res[k][1] = t1[i][1];
            res[k][2] = t1[i][2];
            i++; k++;
        }
        else if(t2[j][0] < t1[i][0] || (t2[j][0] == t1[i][0] && t2[j][1] < t1[i][1])) {
            res[k][0] = t2[j][0];
            res[k][1] = t2[j][1];
            res[k][2] = t2[j][2];
            j++; k++;
        }
        else { // same row and column, add values
            res[k][0] = t1[i][0];
            res[k][1] = t1[i][1];
            res[k][2] = t1[i][2] + t2[j][2];
            i++; j++; k++;
        }
    }

    while(i <= t1[0][2]) {
        res[k][0] = t1[i][0];
        res[k][1] = t1[i][1];
        res[k][2] = t1[i][2];
        i++; k++;
    }

    while(j <= t2[0][2]) {
        res[k][0] = t2[j][0];
        res[k][1] = t2[j][1];
        res[k][2] = t2[j][2];
        j++; k++;
    }

    res[0][2] = k - 1;
}

int main() {
    int n1, m1, n2, m2;
    int k1, k2;

    // Input dimensions for both matrices
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d%d", &n1, &m1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d%d", &n2, &m2);

    // Check if addition is possible
    if(n1 != n2 || m1 != m2) {
        printf("Matrix addition not possible (different sizes).\n");
        return 0;
    }

    // Read elements of Matrix A
    printf("Enter elements of Matrix A:\n");
    for(i = 0; i < n1; i++)
        for(j = 0; j < m1; j++)
            scanf("%d", &a[i][j]);

    // Read elements of Matrix B
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

    // Add triplets
    addTriplet(b, d, res);

    // Print result
    printf("\nResultant Triplet Matrix after Addition:\n");
    printTriplet(res);

    return 0;
}

