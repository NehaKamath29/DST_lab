#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *head)
{
    int i;
    i=0;
    if(head==NULL)
    printf("Nothing to display!\n");
    else
    {
    struct Node *ptr=head;
    while(ptr!=NULL)
    {
        
        printf("Element %d is %d\n",(i+1),(ptr->data));
       // printf("%d\n",ptr->data);
        ptr=ptr->next;
        i++;
    }
}
}
struct Node *insertAtFirst(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    else
    {
    
    ptr->next=head;
    head=ptr;
    return head;
    }
    
}
struct Node *insertInBet(struct Node *head,int data,int index)
{
    int i=0;
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    else
    {
    struct Node *p=head;
    
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    
    ptr->data=data;
    
    ptr->next=p->next;
    p->next=ptr;
    return head;
   }
}
struct Node *insertAtEnd(struct Node *head,int data)
{
    
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    else
    {
    struct Node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    
    ptr->next=NULL;
    p->next=ptr;
    return head;
    }
}
void main()
{
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    head->data=1;
    head->next=NULL;
    int c,data,index;
    while(1)
    {
        printf("Enter 1 to insert at the beginning.\nEnter 2 to insert in between.\nEnter 3 to insert at the end.\nEnter 4 to display.\nEnter 5 to exit!\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("Enter the value to be inserted at the beginning:\n");
            scanf("%d",&data);
            head=insertAtFirst(head,data);
            break;

            case 2:
            printf("Enter the value to be inserted:\n");
            scanf("%d",&data);
            printf("Enter the index where the value has to be inserted:\n");
            scanf("%d",&index);
            head=insertInBet(head,data,index);
            break;

            case 3:
            printf("Enter the value to be inserted at the end:\n");
            scanf("%d",&data);
            head=insertAtEnd(head,data);
            break;

            case 4:
            display(head);
            break;

            case 5:
            exit(0);

            default:
            printf("Invalid choice!\n");
        }
    }
}