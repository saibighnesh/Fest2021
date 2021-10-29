#include <iostream>

using namespace std;

void InsertionSort(int a[], int n){
    for(int i =1; i<n; i++){
        int temp = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > temp){
            a[j+1] =a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void printArray(int arr[], int n){
    for(int i =0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main()
{
    int l;
    cin >> l;
    int *arr = new int [l];
    for (int i = 0; i<l; i++){
        cin >> arr[i] ;
    }
   InsertionSort(arr,l);
    printArray(arr,l);
}
