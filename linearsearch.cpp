#include<iostream>
using namespace std;
void linear_search(int arr[],int l,int n){
    for(int i=0;i<l;i++){
        if(arr[i]==n){
            cout<<"Element found at index:"<<i<<" position"<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}
int main(){
    int arr[]={21,3,4,1,5,6};
    int len=sizeof(arr)/sizeof(arr[0]);
    int n;
    cout<<"enter the element to search:";
    cin>>n;
    linear_search(arr,len,n);
    return 0;
}