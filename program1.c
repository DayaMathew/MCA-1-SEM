
#include<stdio.h>
int a=10;
void stati()
{
static int i = 10;
    printf("Static variable value: %d\n", i++);
}
void regi()
{
 register int e=15;
 printf("Register variable value: %d\n", e++);
}
void glob()
{
    printf("Global variable a: %d\n", a);
    a++;     // increment global variable
}
void local()
{
    int b = 20;   // Local variable
    printf("Local variable b: %d\n", b);
    b++;      // increments, but resets next call (always 20+1 only once)
}
int main()
{
    printf("STATIC\n");
    stati();
    stati();
    stati();
    printf("\nREGISTER\n");
    regi();
    regi();
    regi();
    printf("\nGLOBAL\n");
    glob();
    glob();
    glob();
    printf("\nLOCAL\n");
    local();
    local();
    local();
    return 0;
}

