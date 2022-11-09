#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
}treenode;
void insertion(treenode **root,int x){
    treenode *ptr,*prev,*p;
    ptr=(treenode*)malloc(sizeof(treenode));
    ptr->data = x;
    ptr->right = ptr->left = NULL;
    p=*root;
    prev=NULL;
    while(p!=NULL){
        prev=p;
        if(x<p->data){
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    if(prev==NULL){
        *root = ptr;
    }
    else{
        if(x<prev->data){
            prev->left = ptr;
        }
        else{
            prev->right = ptr;
        }
    }
}

void inorder(treenode *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        printf(" ");
        inorder(root->right);
    }
}

void preorder(treenode *root){
    if(root!=NULL){
        printf("%d",root->data);
        printf(" ");
        preorder(root->left);
        preorder(root->right);

    }
}

void postorder(treenode *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
        printf(" ");
    }
}

void main(){
    treenode *root;
    root=NULL;
    int c,o,n,x;
    do{
        printf("\nMenu\n1.Add\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\nEnter your choice");
        scanf("%d",&c);
        switch(c){
            case 1:
            printf("\nEnter the element to be adder");
            scanf("%d",&x);
            insertion(&root,x);
            break;
            case 2:
            inorder(root);
            break;
            case 3:
            preorder(root);
            break;
            case 4:
            postorder(root);
            break;
            case 5:
            break;
        }
    }while(c!=5);
}