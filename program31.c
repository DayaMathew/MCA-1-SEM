 /*program implement heapsort
@Daya Mathew
Roll no:20
28-07-2025 */
#include <stdio.h>

// Function to heapify a subtree rooted with node i
// n is the size of the heap
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    int i;
    for ( i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (i = n - 1; i > 0; i--)
    {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print array
void printArray(int arr[], int n)
{
	int i;
    for ( i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{ 
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for ( i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array (Heap Sort): ");
    printArray(arr, n);

    return 0;
}

