#include<iostream>
using namespace std;

int binarySearch(int a[],int x,int n){
    int l=0,r=n-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(a[mid]==x)return mid;
        else if(a[mid]>x)r=mid-1;
        else l=mid+1;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter size of the sorted array: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements of array in sorted ascending order: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cout<<"Enter element to be searched: ";
    cin>>x;
    if(binarySearch(a,x,n)==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<"Element found at "<<binarySearch(a,x,n)+1<<endl;
    }
    return 0;
}
