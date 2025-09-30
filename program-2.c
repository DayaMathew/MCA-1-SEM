/* menu driven program to insert,search,delete and sort elements in an array (use global variable)
Daya Mathew
26 July 2025 */

#include<stdio.h>
int arr[50],i,n,a,ch,j,temp,found,pos;
void insert()
{
	printf("enter the number of elements");
	scanf("%d",&n);
	printf("enter elements ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}
void search()
{
	found=0;
	printf("enter the element to search\n");
	scanf("%d",&a);
	for(i=0;i<n;i++)
	{
		if(arr[i]==a)
		{
			printf("element is present at position%d\n",i);
			found=1;
			break;
		}
	}
 	if(found==0)
		{
			printf("element is not present\n");
		}
}

void delete()
{
	printf("enter the position to delete");
	scanf("%d",&pos);
	if(pos<1||pos>n)
		{ 
			printf("invalid position");
		
		}
		else
		{
			for(i=pos;i<n;i++)
			{
				arr[i]=arr[i+1];
			}n--;
		printf("element deleted.\n new array\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
		}
		printf("\n");
	}
}
void sort()
{
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
printf("sorted array\n");
for(i=0;i<n;i++)
{
	printf(" %d\t",arr[i]);

}printf("\n");
}
int main()
{
	while(1)
	{
		
	printf("1.insert\n2.search\n3.delete\n4.sort");
	printf("\nenter choice");
	scanf("%d",&ch);
		
	
	switch(ch)
	{
		case 1:
			
				insert();
				break;
		case 2:
				search();
				break;
		case 3:
				delete();
				break;
		case 4: 
				sort();
				break;
		default :
				printf("you entered wrong choice");
				return 0;
				
	}}
return 0;
}
