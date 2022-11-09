#include <stdio.h>
#define Max 5

int queue[Max];
int front=0,rear=-1;

void insert(int val);
int delete(void);
int peek(void);
void display(void);

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
    return 0;
}

void insert(int val){
 //   int num;
  //  printf("\nEnter the number to be inserted in queue");
  //  scanf("%d,&num");
    if(rear==Max-1){
        printf("\n Overflow");
    }
    else{
        rear++;
        queue[rear]=val;
    }
}

int delete(){
    int val;
    if(front>rear){
        printf("\nUnderflow");
        return -1;
    }
    else{
        val=queue[front];
        front++;
    }
    return val;
}

int peek(){
    int val;
    if(rear==-1){
        printf("\nEmpty");
        return -1;
    }
    else{
        val = queue[front];
    }
    return val;
}

void display(){
        if(rear==-1){
        printf("\nEmpty");
    }
    for(int i=0;i<=rear;i++){
        printf("\t%d",queue[i]);
    }
}