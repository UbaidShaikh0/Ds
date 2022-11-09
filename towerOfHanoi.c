#include <stdio.h>
#include <stdlib.h>

void main(){
    void move(int n,char source,char dest,char aux);
    int n;
    printf("Enter no of disk");
    scanf("%d",&n);
    move(n,'A','C','B');
}

void move(int n,char source,char dest,char aux){
    if(n==1){
        printf("\n Move from %c to %c",source,dest);
    }
    else{
        move(n-1,source,aux,dest);
        move(1,source,dest,aux);
        move(n-1,aux,dest,source);
    }
}