/*  stack operations  using arrays
Daya Mathew
26 July 2025 */
#include<stdio.h>
#define SIZE 100
int stack[SIZE];
int top=-1;
void push(int value)
{
	if(top==SIZE-1)
	{
		printf("stack overflow\n");
	}
	else
	{
		top++;
		stack[top]=value;
		printf("%d pushed to stack\n",value);
	}
	
}
void pop()
{
	if(top==-1)
	{
		printf("stack underflow\n");
	}
	else
	{
		printf("%d popped from stack\n",stack[top]);
		top--;
	}
}
void peek()
{
	if(top==-1)
	{
		 printf("stack is empty");
	}
	else
	{
		printf("top element %d\n",stack[top]);
	}
}
void display()
 {
 	int i;
    if (top == -1)
	 {
        printf("Stack is empty\n");
    } 
	else
	 {
        printf("Stack elements: ");
        for (i = top; i >= 0; i--) 
		{
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
 {
    int choice, value;

    while (1)
	 {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
		 {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
    	}
}
}
        
