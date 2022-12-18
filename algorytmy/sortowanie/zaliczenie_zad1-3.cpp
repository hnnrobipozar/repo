#include <iostream>

using namespace std;

void printArray(int arr[], int size){

    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

///////////////////////////////////////////////////1
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

void sortArr(int *tab, int first, int size){
    cout<<"Tablica przed sortowaniem:"<<endl;
    printArray(tab, size);
    mergeSort(tab, first, size-1);
    cout<<"Tablica po sortowaniu:"<<endl;
    printArray(tab, size);
}
///////////////////////////////////////////////////2



///////////////////////////////////////////////////3
void swap(int* a, int* b){

    int t = *a;
    *a = *b;
    *b = t;
}
  
int partition(int arr[], int low, int high){

    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) {
        
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  
void quickSort(int arr[], int low, int high){

    if (low < high) {
        
        int pi = partition(arr, low, high);
  
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void greatestMulti(int *tab, int size){
    
    cout<<"Tablica: "<<endl;
    printArray(tab, size);
    quickSort(tab, 0, size - 1);
    int m1 = (tab[size-1] * tab[size-2]);
    int m2 = (tab[0] * tab[1]);
    int m = m1 > m2 ? m1 : m2;
    cout<<"Najwiekszy iloczyn to: ";
    if(m1 > m2){
        cout<<"("<<tab[size-1]<<" * "<<tab[size-2]<<") = "<<m<<endl;
    }
    else{
        cout<<"("<<tab[0]<<" * "<<tab[1]<<") = "<<m<<endl;
    }
}

int main(){
//ad1
    cout<<endl<<"Zadanie 1:"<<endl;
    int arr1[] = {1, 3, 5, 7, 9, 11, 10, 8, 6, 4, 2};
    int N1 = sizeof(arr1)/sizeof(arr1[0]);
    sortArr(arr1, 0, N1);
    cout<<"**************************************"<<endl;

//ad2
    cout<<endl<<"Zadanie 2:"<<endl;


    cout<<"**************************************"<<endl;

//ad3
    cout<<endl<<"Zadanie 3:"<<endl;
    int arr3[]={7,2,33,9,-99,-1,4,-111};
    int N3 = sizeof(arr3) / sizeof(arr3[0]);
    greatestMulti(arr3,N3);
    cout<<"**************************************"<<endl;

   
    return 0;
}