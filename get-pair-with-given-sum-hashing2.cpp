#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]= {2,2,3,4,15,10,9,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum=13;
    unordered_set<int> set;
    for(int i=0;i<n;i++){
        if(set.find(sum-arr[i])!=set.end()){
            cout<<arr[i]<<","<<sum-arr[i]<<endlṆ;
        }
        set.insert(arr[i]);
    }
    return 0;

}