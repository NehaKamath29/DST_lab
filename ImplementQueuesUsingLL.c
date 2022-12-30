/*Queue using Linked lists*/

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
    struct Node *ptr=head;
    i=0;
    if(head==NULL)
    {
        printf("Nothing to display!\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("Element %d is %d\n",(i+1),(ptr->data));
            ptr=ptr->next;
            i++;
        }
    }
}
struct Node *insert_rear(struct Node *head,int data)
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
struct Node *delete_front(struct Node *head)
{
    if(head==NULL)
    {
        printf("Nothing to delete, the queue is empty!\n");
        return NULL;
    }
    else
    {
    struct Node *p=head;
    printf("The deleted element is %d\n",p->data);    
    head=head->next;
    free(p);
    return head;
    }
}
void main()
{
    struct Node *head=NULL;
    int c,data;
    while(1)
    {
        printf("Enter 1 to insert values into the queue.\nEnter 2 to delete values from the queue.\nEnter 3 to display.\nEnter 4 to exit.\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("Enter the value to be inserted:\n");
            scanf("%d",&data);
            head=insert_rear(head,data);
            break;
            
            case 2:
            head=delete_front(head);
            break;
            
            case 3:
            display(head);
            break;
            
            case 4:
            exit(0);
            
            default:
            printf("Invalid choice!\n");
        }
    }
}

