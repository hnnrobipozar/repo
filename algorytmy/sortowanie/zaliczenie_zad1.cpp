#include <iostream>


using namespace std;
///////////////////////////////////////////////////
//insertion sort
int c=0;

int insertionSort(int arr[], int n)
{
    int i, key, j, counter = 0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            counter++;
        }
        arr[j + 1] = key;
    }
    return counter;
}
 
// A utility function to print an array
// of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
///////////////////////////////////////////////////
//merge sort

void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  auto const n1 = q - p + 1;
  auto const n2 = r - q;
  

  //int L[n1], M[n2];
  auto *L = new int[n1];
    auto *M = new int[n2];


  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
int mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
    c++;
  }
  return c;
}



int main(){

    int arr[] = {1, 3, 5, 7, 9, 11, 10, 8, 6, 4, 2};
    int N = sizeof(arr)/sizeof(arr[0]);

    cout<< insertionSort(arr, N)<<endl;
    printArray(arr, N);

    int arr1[] = {1, 3, 5, 7, 9, 11, 10, 8, 6, 4, 2};
    int N1 = sizeof(arr1)/sizeof(arr1[0]);

    cout<<mergeSort(arr1, 0, N1-1)<<endl;
    printArray(arr1, N1);

    


    return 0;
}