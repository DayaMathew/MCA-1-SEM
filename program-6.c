/*program to display the array elements in the same order using recursive function
@Daya Mathew
28-07-2025 */

#include<stdio.h>
int a[10],num;
void display(int i)
{
    if (i == num) 
    return;
    printf("%d ", a[i]);
    display(i + 1); 
}
 

int main()
{      
       int i;
	printf("Enter the number of elements in an array:");
	scanf("%d",&num);
	printf("Enter elements in array:");
	for(i = 0; i < num; i++)
       {
           scanf("%d", &a[i]);
       }
        printf("The elements in array:");
	display(0);
}
 


