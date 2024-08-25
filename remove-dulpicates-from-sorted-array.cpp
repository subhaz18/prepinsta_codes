#include <bits/stdc++.h>
using namespace std;

int removeduplicates(int arr1[], int n)
{
    if(n==0 ||n==1){
        return n;
    }
    int j=0;
    for(int i=0;i<n;i++){
        if(arr1[i]!=arr1[i+1]){
            arr1[j]=arr1[i];
            j++;
        }
    }
   // arr1[j]=arr1[n-1];
    //j++;
   

    return j;
}

int main()
{
    int arr1[] = {1,1,1,2,2,2,3,3,4,4};
    //int arr2[] = {1, 5, 5, 8, 1, 8, 7};
    

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    //int size2 = sizeof(arr2) / sizeof(arr2[0]);
    //sort(arr1,arr1+size1);
    int k=removeduplicates(arr1, size1);

    for (int i=0;i<k;i++)
        cout << arr1[i] << " ";


    return 0;
}