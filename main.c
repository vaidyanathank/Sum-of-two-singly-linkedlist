#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=0;
struct Node *tail=0;

struct Node *head1=0;
struct Node *tail1=0;

int count1=0;
int count2=0;

void createNode(int n){
    if(head==NULL){
        head=malloc(sizeof(struct Node));
        head->data=n;
        head->next=NULL;
        tail=head;
    }
    else{
        struct Node *t=malloc(sizeof(struct Node));
        t->data=n;
        t->next=NULL;
        tail->next=t;
        tail=t;
    }
    count1++;
}

void createNode1(int n){
    if(head1==NULL){
        head1=malloc(sizeof(struct Node));
        head1->data=n;
        head1->next=NULL;
        tail1=head1;
    }
    else{
        struct Node *t=malloc(sizeof(struct Node));
        t->data=n;
        t->next=NULL;
        tail1->next=t;
        tail1=t;
    }
    count2++;
}

void display(struct Node *start){
    while(start!=NULL){
        printf("%d ",start->data);
        start=start->next;
    }
}

void add(){
    int s=count1-count2;
    struct Node *p=head;
    for(int i=0;i<s;i++){
        p=p->next;
    }
    struct Node *q=head1;
    while(p!=NULL){
        p->data=p->data+q->data;
        p=p->next;
        q=q->next;
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    int a1[]={3,4,5};
    int size1=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<size1;i++)
        createNode(a[i]);
    
    int size2=sizeof(a1)/sizeof(a1[0]);
    for(int i=0;i<size2;i++)
        createNode1(a1[i]);
    
    display(head);
    printf("\n");
    display(head1);
    printf("\n");
    
    add();
    display(head);
    printf("\n");
    
    return 0;
}