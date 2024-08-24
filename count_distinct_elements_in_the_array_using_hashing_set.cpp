// Single Insertion in Set : O(1)
// For n Elements : O(n),
// Thus, Time complexity : O(n) Traverse set to count distinct
// Space Complexity: O(n) for Extra memory for set creation

#include <bits/stdc++.h>
using namespace std;

int countDistinct(int arr[], int size)
{
    unordered_set<int> set;   //or simple use this one line unordered_set<int> set(arr,arr+size);
    for (int i = 0; i < size; i++)   //
        set.insert(arr[i]);

    return set.size();
}

int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << countDistinct(arr, size);

    return 0;
}