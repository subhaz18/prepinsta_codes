#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

int largestHistRow(int arr[], int n) {
    stack <int> s;

    int res = 0;
    int top_index;
    int curr;

    for (int i = 0; i < n; i++) {
        while (s.empty() == false && arr[s.top()] >= arr[i]) {
            top_index = s.top();
            s.pop();
            curr = arr[top_index] * (s.empty() ? i : i - s.top() - 1);
            res = max(res, curr);
        }
        s.push(i);
    }
    while (s.empty() == false) {
        top_index = s.top();
        s.pop();
        curr = arr[top_index] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }

    return res;

}

int MaxArea(int mat[][C])
{
    int res = largestHistRow(mat[0], C);

    for (int i = 1; i < R; i++) {

        for (int j = 0; j < C; j++)
            if (mat[i][j])
                mat[i][j] += mat[i - 1][j];

        res = max(res, largestHistRow(mat[i], C));
    }
    return res;
}

int main()
{
    int mat[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };

    cout << "Maximum rectangle is:  " << MaxArea(mat);

    return 0;
}