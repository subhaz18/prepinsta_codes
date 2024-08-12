#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={34,1,2,53,45,21,12,23};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}