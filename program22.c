/*program to read and display a sparse matrix
@Daya Mathew
08-09-2025 */

#include<stdio.h>
int main(){
    int n,m;
    printf("\nEnter the number of rows and columns:");
    scanf("%d%d",&n,&m);

    // Original matrix (a) and Triplet representation (b)
    int a[m][n],b[m][n],i,j;
    
    // Input matrix elements
    printf("\nEnter the elements:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    
    // Count non-zero elements
    int count=0;        
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j] != 0){
                count++;
            }
        }
    }
    
    // First row of triplet: rows, columns, total non-zero count
    b[0][0]=n;
    b[0][1]=m;
    b[0][2]=count;
    
    int k=1; // index for triplet
    
    // Store non-zero elements in triplet form
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j] != 0){
                b[k][0] = i;        // Row index
                b[k][1] = j;        // Column index
                b[k][2] = a[i][j];  // Value
                k++;
            }
        }
    }
    
    // Print triplet form
    printf("\nSparse matrix (Triplet form):\n");
    for(i=0;i<k;i++){
        printf("%d %d %d",b[i][0],b[i][1],b[i][2]);
        printf("\n");
    }
}

