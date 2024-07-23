#include<iostream>
using namespace std;
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void swap(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int swapindex=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<=pivot){
            swapindex++;
            swap(&arr[swapindex],&arr[j]);
        }
    }
    swap(&arr[swapindex+1],&arr[high]);
    return (swapindex+1);
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int indexpt=partition(arr,low,high);

        quicksort(arr,low,indexpt-1);
        quicksort(arr,indexpt+1,high);
    }
}




int main(){
    int arr[]={70,30,50,60,87,90,45};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"before sorting \n";
    display(arr,n);
    quicksort(arr,0,n-1);
    cout<<"\nafter sorting\n";
    display(arr,n);
    return 0;
}