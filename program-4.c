/* program to search for all occurences of an element in an integer array
Daya Mathew
27 July 2025 */

#include<stdio.h>
int main()
{
	int a[100],i,n,s,found=0;
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the elements ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	printf("enter the element to search");
	scanf("%d",&s);
	printf("element %d found at postions:\n",s);
	for(i=0;i<n;i++)
	{
		if(s==a[i])
		{
			printf("%d\t",i);
			found++;
		
		}
	}
	if(found==0)
	{
			printf("element is   not found");
	}
	else
	{
	
		printf("\ntotal occurences=%d",found);
	}		
return 0;
}
