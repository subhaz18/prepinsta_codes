// Time Complexity : O(n^2)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

int getunion(int *arr,int *arr1 , int n,int m,vector<int> &result) {

    for (int i = 0; i < n; i++) {
        int flag = 0;
        //int count = 0;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                flag = 1;
                break;
            }
        }

        // The continue keyword is used to end the current iteration
        // in a for loop (or a while loop), and continues to the next iteration
        if (flag == 0)
            result.push_back(arr[i]);
    }

       for (int i = 0; i < m; i++) {
        int flag = 0;
        //int count = 0;

        for (int j = i + 1; j < m; j++) {
            if (arr1[i] == arr1[j]) {
                flag = 1;
                break;
            }
        }

        // The continue keyword is used to end the current iteration
        // in a for loop (or a while loop), and continues to the next iteration
        if (flag == 0){
            if( (std::find(result.begin(), result.end(), arr1[i]) != result.end())==1){
                break;
            }
            else{
                result.push_back(arr1[i]);
            }
        }
            
    }

   // return result

}

int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10,15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int arr1[] = {1,5,5,8,1,8,7,13};
    int size1 = sizeof(arr) / sizeof(arr[0]);
    vector<int> result;
    getunion(arr,arr1, size,size1,result);
    for(auto x:result){
        cout<<x<<" ";
    }
    return 0;
}