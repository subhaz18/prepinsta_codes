#include<iostream>
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        while(j>=0){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
            else{
                break;
            }
            j--;
    }
}
}

int main(){
    int arr[10]={1,4,5,2,7,3,10,6,9,8};
    int len=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,len);
    printf("array after sorting:");
    for(int k=0;k<len;k++){
        printf("%d ",arr[k]);
    }
    return 0;
}