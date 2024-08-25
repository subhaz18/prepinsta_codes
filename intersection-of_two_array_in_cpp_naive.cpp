// Time complexity : O(m*(m+n), Auxiliary space complexity O(1)
// m = Size of array 1, n = size of array 2

#include <bits/stdc++.h>
using namespace std;

// Note : Ideally the question comes to print number of common elements
// But, we have made it a little more complicated by forcefully asking user to pass
// the array back to main function and print common elements
// We have passed vector to demonstrate how vectors can be passed but,
// You can pass array by address too, back to the main function
// If you just need to print the count, don't pass Vector just pass count
// Just increment the count Whenever, we are push_back to vector

int getIntersection(int *arr1, int *arr2, int size1, int size2, vector <int> &result) {

    for (int i = 0; i < size1; i++) {
        int flag = 0;

        for (int j = i + 1; j < size1; j++) {
            if (arr1[i] == arr1[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            continue;

        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                result.push_back(arr1[i]);
                break;
            }
        }
    }
}

int main()
{

// Time complexity : O(m*(m+n), Auxiliary space complexity O(1)
// m = Size of array 1, n = size of array 2

    int arr1[] = {5, 8, 5, 7, 8, 10};
    int arr2[] = {1, 5, 5, 8, 1, 8, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    vector <int> result;
    getIntersection(arr1, arr2, size1, size2, result);

    for (auto x : result)
        cout << x << " ";

    return 0;
}