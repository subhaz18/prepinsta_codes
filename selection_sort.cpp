#include<iostream>
void selection_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
    }
    int temp=arr[min];
    arr[min]=arr[i];
    arr[i]=temp;
}
}

int main(){
    int arr[10]={1,4,5,2,7,3,10,6,9,8};
    int len=sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,len);
    printf("array after sorting:");
    for(int k=0;k<len;k++){
        printf("%d ",arr[k]);
    }
    return 0;
}