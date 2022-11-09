#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 10
char st[Max];
int top = -1;
void push(char st[],char);
char pop(char st[]);
void balanceParanthesis(char source[]);

int main(){
    char infix[10];
    printf("Enter the infix expression");
    gets(infix);
    balanceParanthesis(infix);
    getch();
    return 0;
}

void balanceParanthesis(char source[]){
    int i=0;
    int c=0;
    while(source[i]!='\0'){
        if(source[i]=='('){
            push(st,source[i]);
        }
        else if(source[i]==')' && source[top]=='('){
            pop(st);
        }
        else if(source[i]==')'){
            c++;
        }
        i++;
    }
    if(top == -1 && c==0){
        printf("The Brackets are Balanced");
    }
    else{
        printf("not balanced");
    }
}

void push(char st[],char val){
    if(top == Max-1){
        printf("Stack overflow");
    }
    else{
        st[++top] = val;
    }
}

char pop(char st[]){
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        return st[top--];
    }
}