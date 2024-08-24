// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

void countFrequency(int arr[], int size)
{
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
        map[arr[i]]++;

    for (auto x : map)
        cout << x.first << ": " << x.second << endl;

}

int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    countFrequency(arr, size);

    return 0;
}