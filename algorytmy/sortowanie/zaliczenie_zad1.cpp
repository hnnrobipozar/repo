#include <iostream>


using namespace std;


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
  
  auto const n1 = q - p + 1;
  auto const n2 = r - q;
  
  auto *L = new int[n1];
  auto *M = new int[n2];


  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

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


void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    
    merge(arr, l, m, r);
    
  }
}



int main(){

    int arr1[] = {1, 3, 5, 7, 9, 11, 10, 8, 6, 4, 2};
    int N1 = sizeof(arr1)/sizeof(arr1[0]);

    mergeSort(arr1, 0, N1-1);
    printArray(arr1, N1);

    


    return 0;
}