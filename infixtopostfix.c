#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define Max 100
char st[Max];
int top = -1;
void push(char st[], char);
char pop(char st[]);
int getPriority(char);
void infixToPostfix(char source[], char target[]);

int main()
{
    char infix[100];
    char postfix[100];
    printf("Enter any infix expression");
    gets(infix);
    strcpy(postfix, " ");
    infixToPostfix(infix, postfix);
    printf("the postfix expression is : ");
    puts(postfix);
    getch();
    return 0;
}

void infixToPostfix(char source[], char target[])
{
    int i = 0;
    int j = 0;
    char temp;
    strcpy(target, " ");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(st, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (st[top] != '('))
            {
                target[j] = pop(st);
                j++;
            }
            if (top == -1)
            {
                printf("incorrect expression");
                exit(1);
            }
            pop(st);
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (st[top] != '(') && (getPriority(st[top]) > getPriority(source[i])))
            {
                target[j] = pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        }
        else
        {
            printf("\n Incorrect element in the expression");
            exit(1);
        }
    }
    while ((top != -1) && (st[top] != '('))
    {
        target[j] = pop(st);
        j++;
    }
    target[j] = '\0';
}

int getPriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
    {
        return 1;
    }
    else if (op == '+' || op == '-')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void push(char st[],char val){
    if(top==Max-1){
        printf("stack overflow");
    }
    else{
        st[++top]=val;
    }
}

char pop(char st[]){
    char val = ' ';
    if(top==-1){
        printf("stack is empty");
    }
    else{
        val = st[top--];
    }
    return val;
}