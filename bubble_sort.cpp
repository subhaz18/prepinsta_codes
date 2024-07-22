#include<iostream>
void bubble_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
    }
}
}

int main(){
    int arr[10]={1,4,5,2,7,3,10,6,9,8};
    int len=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,len);
    printf("array after sorting:");
    for(int k=0;k<len;k++){
        printf("%d ",arr[k]);
    }
    return 0;
}