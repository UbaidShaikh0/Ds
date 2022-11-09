#include <stdio.h>
#include <conio.h>
#define Max 5

int queue[Max];
int front=-1,rear=0;

void insert(int val);
int delete();
int peek();
void display();

int main(){
    int option,val;
    do{
        printf("Press 1 for inserth\n");
        printf("Press 2 for delete\n");
        printf("Press 3 for peek\n");
        printf("Press 4 for display\n");
        printf("Press 5 for exit\n");
        printf("Enter the option\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("\nEnter the element");
                scanf("%d",&val);
                insert(val);
                break;
            case 2:
                val = delete();
                if(val!=-1){
                    printf("the number deleted is %d",val);
                }
                break;
            case 3:
                val=peek();
                if(val!=-1){
                    printf("the first element queue is %d",val);
                }
                break;
            case 4:
                display();
                break;
        }
    }while(option!=5);
    getch();
    return 0;
}

void insert(int val){
    if(front == (rear+1)%Max){
        printf("\nOverflow");
    }
    else if(front == -1 && rear == 0){
        front=rear=0;
        queue[rear]=val;
    }
    else{
        rear = (rear+1)%Max;
        queue[rear] = val;
    }
}

int delete(){
    int val = -1;
    if(front==-1 && rear==0){
        printf("\nQueue is empty");
        return val;
    }
    if(front==rear){
        val = queue[rear];
        front=-1;
        rear=0;
        }
        else{
            val=queue[front];
            front=(front+1)%Max;
        }
    return val;
}

int peek(){
    if(front == -1 && rear == 0){
        printf("\nUnderflow");
        return -1;
    }
    else{
        return queue[front];
    }
}

void display(){
    int i,f=front,r=rear;
    printf("\n");
    if(front==-1 && rear==0){
        printf("\nQueue is empty");
    }
    else{
        while(f!=r){
            printf("\t%d",queue[f]);
            f=(f+1)%Max;
        }
        printf("\t%d",queue[f]);
    }
}