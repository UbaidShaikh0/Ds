#include <stdio.h>
#include <stdlib.h>
#define Max 3
int top=-1;
int st[Max];
void push(int st[],int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main(){
    int val,option;
    do{
        printf("Press 1 for push\n");
        printf("Press 2 for pop\n");
        printf("Press 3 for peek\n");
        printf("Press 4 for peak\n");
        printf("Press 5 for exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("enter the number to push");
                scanf("%d",&val);
                push(st,val);
                break;
            case 2:
                val=pop(st);
                if(val!=-1){
                    printf("The value deleted fro the stack is %d",val);
                    break;
                }
            case 3:
                val=peek(st);
                if(val!=-1){
                    printf("Peek value is %d",val);
                }
                break;
            case 4:
                display(st);
                break;
        }
    }while(option!=5);
}

void push(int st[],int val){
    if(top==Max-1){
        printf("Stack overflow");
    }
    else{
        st[++top]=val;
        printf("the number added is %d",val);
    }
}

int pop(int st[]){
    if(top==-1){
        printf("Stack underflow");
        return -1;
    }
    else{
        return st[top--];
    }
}

int peek(int st[]){
    if(top==-1){
        printf("Stack underflow");
        return -1;
    }
    else{
        return st[top];
    }
}

void display(int st[]){
    for(int i=top ; i>=0 ; i--){
        printf("%d",st[i]);
        printf("\n");
    }
}