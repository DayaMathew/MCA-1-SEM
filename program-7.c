/*program to display the array elements in reverse order using recursive function
@Daya Mathew
28-07-2025 */


void displayReverse(int arr[], int index) 
{
   
    if (index < 0) 
   {
        return;
   }

    printf("%d ", arr[index]);
    displayReverse(arr, index - 1);
}

int main() 
{
    int arr[100]; 
    int n, i;

   
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) 
	{
        scanf("%d", &arr[i]);
    }

    printf("Array elements in reverse order:\n");
    displayReverse(arr, n - 1); 

}
