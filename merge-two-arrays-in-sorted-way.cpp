#include <bits/stdc++.h>
using namespace std;

vector <int> mergetwoarray(int arr1[], int arr2[], int n, int m, vector<int> &result)
{
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            result.push_back(arr1[i]);
            i++;
        }
        else{
            result.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        result.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        result.push_back(arr2[j]);
        i++;
    }

    // int i = 0, j = 0;

    // // add elements till size1/size2, whichever is smaller
    // while(i<size1 && j<size2){
    //     set1.insert(arr1[i]);
    //     set2.insert(arr2[j]);
    //     i++;
    //     j++;
    // }

    // Optimized method to add elements to set
    // // add remaining elements of arr1, if any
    // while(i<size1){
    //     set1.insert(arr1[i]);
    //     i++;
    // }

    //     // add remaining elements of arr1, if any
    // while(j<size2){
    //     set2.insert(arr2[j]);
    //     j++;
    // }

    return result;
}

int main()
{
    int arr1[] = {5, 8, 5, 7, 8, 10};
    int arr2[] = {1, 5, 5, 8, 1, 8, 7};
    vector<int> result;

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    mergetwoarray(arr1, arr2, size1, size2, result);

    for (auto x : result)
        cout << x << " ";


    return 0;
}