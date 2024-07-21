#include<stdio.h>
int* myf(char str[]){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='a')
        str[i]='z';
        i++;
    }
    return str;
}
int main(){
    char str[]="prepinsta";
    int* p;
    p=myf(str);
    printf("%s",p);
    return 0;
}