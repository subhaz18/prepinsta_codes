#include<iostream>
#include<algorithm>
using namespace std;
int binary_search(int arr[],int len,int k){
    int low=0,high=len-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(k<arr[mid]){
            high=mid-1;
        }
        else if(k>arr[mid]){
            low=mid+1;
        }
        else 
        return mid;
    }
    return -1;
}

int main(){
    int arr[10]={1,4,5,2,7,3,10,6,9,8};
    int len=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr + len);
    int k;
    cout<<"enter the key element:";
    cin>>k;
    int j=binary_search(arr,len,k);
    if(j!=-1)
    cout<<"element found at index:"<<j<<endl;
    else
    cout<<"element not found";
    return 0;
}