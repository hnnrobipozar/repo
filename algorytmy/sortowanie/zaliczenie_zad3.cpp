#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
  
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int najwiekszyIloczynTablicy(int tab[]){
    int n = sizeof(tab) / sizeof(tab[0]);
    quickSort(tab, 0, n - 1);
    printArray(tab, n);
    int iloczyn1 = tab[n-1] * tab[n-2];
    int iloczyn2 = tab[0] * tab[1];
    int iloczyn = iloczyn1 > iloczyn2 ? iloczyn1 : iloczyn2;
    return iloczyn;
}


int main(){

   int t[]={7,2,33,9,-99,-1,4};
   int N = sizeof(t) / sizeof(t[0]);
    quickSort(t, 0, N - 1);
    printArray(t, N);

    //cout << najwiekszyIloczynTablicy(tab);

   
    return 0;
    
}