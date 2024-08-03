#include <stdio.h>
//quicksort uses a pivot to references and compare
//it has a partiticion e a swap method
void printArray(int arr[], int size);
void swap(int* i, int* j);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
    int arr[10] = {9, 2, 13, 31, 5, 4, 9, 3, 1, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array unordered: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Array ordered: ");
    printArray(arr, n);

    return 0;
}
void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
