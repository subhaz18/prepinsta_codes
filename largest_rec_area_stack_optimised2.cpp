#include<bits/stdc++.h>
using namespace std;
int maxarea(int arr[],int n){
    int res=0;
    int top_index;
    int curr;
    stack<int> s;
    for(int i=0;i<n;i++){
        while(s.empty()==false&&arr[s.top()]>=arr[i]){
            top_index=s.top();
            s.pop();
            curr=arr[top_index]*(s.empty()?i:i-s.top()-1);
            res=max(res,curr);
        }
        s.push(i);
    }
    while(s.empty()==false){
        top_index=s.top();
        s.pop();
        curr=arr[top_index]*(s.empty()?n:n-s.top()-1);
        res=max(res,curr);
        }
    return res;

}

int main(){
    
    int arr[] = {12,4,5,5,1,5,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max Area: " << maxarea(arr, n);
    return 0;

}