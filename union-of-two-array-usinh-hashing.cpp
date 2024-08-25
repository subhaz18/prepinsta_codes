// Time Complexity : O(n^2)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10,15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int arr1[] = {1,5,5,8,1,8,7,13};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    //vector<int> result;
    //getunion(arr,arr1, size,size1,result);
    unordered_set<int> result;
    for(int i=0;i<size;i++){
        result.insert(arr[i]);
    }
    for(int i=0;i<size1;i++){
        result.insert(arr1[i]);
    }
    for(auto it=result.begin();it!=result.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}