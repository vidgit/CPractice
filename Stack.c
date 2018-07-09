#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};

void push(struct Node **head,int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL){
        
        *head=newNode;
        return;
    }
    newNode->next=*head;
    *head=newNode;
    
}
int pop(struct Node **head){
    if(*head==NULL)
        return -1;
    int x= (*head)->data;
    *head=(*head)->next;
    return x;
    
}

void printStack(struct Node *head){
    if(head==NULL)
        return;
    printf("%d ",head->data);
    printStack(head->next);
}

int main(){
    struct Node *head=NULL;
    push(&head,1);
    //printf("%d ",head->data);
    //printf("%d",head->next);
    //printStack(head);
    push(&head,2);
    //printf("%d ",head->data);
    //printf("%d", head->next);
    printStack(head);
    printf("\n");
    printf("Value popped= %d\n",pop(&head));
    printStack(head);
    printf("\n");
    printf("Value popped= %d\n",pop(&head));
    printStack(head);
    printf("Value popped= %d\n",pop(&head));
    printStack(head);
}
