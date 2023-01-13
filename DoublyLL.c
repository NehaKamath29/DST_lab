#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *getNode()
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        printf("Memory full!\n");
        return NULL;
    }
    else
    return ptr;
}
void forwardTraversal(struct Node *head)
{
    int i=0;
    if(head==NULL)
    {
        printf("Nothing to display!\n");
        
    }
    else
    {
        struct Node *p=head;
        while(p!=NULL)
        {
            printf("Element %d is %d\n",(i+1),p->data);
            p=p->next;
            i++;
        }
    }
}
struct Node *insert_at_end(struct Node *head,int data, int *c)
{
    struct Node *ptr=getNode();
    ptr->prev=NULL;
    ptr->next=NULL;
    ptr->data=data;
    if(head==NULL)
    {
        return ptr;
        *c=*c+1;
    }
    else
    {
        struct Node *p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        ptr->next=NULL;
        ptr->prev=p;
        p->next=ptr;
        *c=*c+1;
        
        return head;
    }
}
struct Node *insert_to_left(struct Node *head, int data, int index, int *c)
{
     int i=0;
    struct Node *ptr=getNode();
    ptr->prev=NULL;
    ptr->next=NULL;
    ptr->data=data;
    if(index>*c)
    {
        printf("Invalid index!\n");
        return head;
    }
    if(head==NULL)
    {
        return ptr;
        *c=*c+1;
    }
    else
    {
        struct Node *p=head;
        while(i!=index)
        {
            p=p->next;
            i++;
        }
        p->prev->next=ptr;
        ptr->prev=p->prev;
        p->prev=ptr;
        ptr->next=p;
        *c=*c+1;
        return head;
    }
}
struct Node *delete_at_value(struct Node *head, int val)
{
   
    while(head->data==val)
    {
        struct Node *p=head;
        head=head->next;
        head->prev=NULL;
        free(p);
        
    }
    if(head!=NULL)
    {
        struct Node *p=head;
        struct Node *q=head->next;
        while(q->next!=NULL)
        {
            if(q->data==val)
            {
                struct Node *r=q;
                q=q->next;
                p->next=r->next;
                r->next->prev=p;
                free(r);
            }
            else
            {
                p=p->next;
                q=q->next;
            }
        }
    
        if(q->next==NULL && q->data==val)
        {
            p->next=NULL;
            free(q);
            return head;
        }
        else
        return head;
    }
    return head;
}
void main()
{
    int count=0;
    struct Node *head=NULL;
    int n,i;
    int c,data,index;
    while(1)
    {
        printf("Enter 1 to create a doubly linked list\nEnter 2 to insert to the left of the node.\nEnter 3 to delete the node having specified value.\nEnter 4 to display.\n");
        printf("Enter 5 exit.\n");
       scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("Enter the value to be inserted:\n");
            scanf("%d",&data);
            head=insert_at_end(head, data, &count);
            break;
            
            case 2:
            printf("Enter the value to be inserted:\n");
            scanf("%d",&data);
            printf("Enter the index to the left of which the node has to be inserted:\n");
            scanf("%d",&index);
            head=insert_to_left(head,data,index, &count);
            break;

            case 3:
            printf("Enter the value to be deleted:\n");
            scanf("%d",&data);
            head=delete_at_value(head,data);
            break;

            case 4:
            forwardTraversal(head);
            break;

            case 5:
            exit(0);

            default:
            printf("Invalid choice!\n");
        }
    }
}
    
