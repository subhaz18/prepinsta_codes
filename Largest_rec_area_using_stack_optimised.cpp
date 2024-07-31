#include<bits/stdc++.h>
using namespace std;
int maxarea(int arr[],int n){
    int res=0;
    int prevstack[n],nextstack[n];
    stack<int> s;
    s.push(0);
    for(int i=0;i<n;i++){
        while(s.empty()==false&&arr[s.top()]>=arr[i]){
            s.pop();
        }
        int p=s.empty()?-1:s.top();
        prevstack[i]=p;
        s.push(i);
    }
    while(s.empty()==false){
        s.pop();
    }
    s.push(n-1);
    for(int i=n-1;i>=0;i--){
        while(s.empty()==false&&arr[s.top()]>=arr[i]){
            s.pop();
        }
        int p=s.empty()?-1:s.top();
        nextstack[i]=p;
        s.push(i);
    }
    for(int i=0;i<n;i++){
        int t=arr[i];
        t+=(i-prevstack[i]-1)*arr[i];
        t+=(nextstack[i]-i-1)*arr[i];
        res=max(res,t);
    }
    return res;

}

int main(){
    
    int arr[] = {12, 2, 5, 4, 1, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max Area: " << maxarea(arr, n);
    return 0;

}