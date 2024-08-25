#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]= {2,2,3,4,15,10,9,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum=13;
    unordered_set<int> set;
    for(int i=0;i<n;i++){
        set.insert(arr[i]);
    }
    for(auto x :set){
        if(set.count(sum-x)){
            cout<<x<<","<<sum-x<<endl;
            set.erase(sum-x);
        }
    }
    return 0;
}