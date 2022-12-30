#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void show(struct Node *head)
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
struct Node *deleteAtFirst(struct Node *head)
{
    if(head==NULL)
    {
        printf("No linked list!\n");
        return NULL;
    }
    else
    {
    struct Node *p=head;
    head=head->next;
    free(p);
    return head;
    }
}
struct Node *deleteInBet(struct Node *head,int index)
{
    if(head==NULL)
    {
        printf("No linked list!\n");
        return NULL;
    }
    else
    {
    int i=0;
    struct Node *p=head;
    struct Node *q=head->next;
    while(i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}
}
struct Node* deleteAtEnd(struct Node *head)
{
    if(head==NULL)
    {
        printf("Nothing to delete!\n");
        return NULL;
    }
    else
    {
    int i=0;
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=NULL;
    free(q);
    return head;
}
}

void main()
{
    struct Node *head=NULL;
    int c,data,index,i;
    while(1)
    {
        printf("Enter 1 to insert at the beginning.\nEnter 2 to insert in between.\nEnter 3 to insert at the end.\n");
        printf("Enter 4 to delete at the beginning.\nEnter 5 to delete in between.\nEnter 6 to delete at the end.\n");
        printf("Enter 7 to display.\nEnter 8 to exit!\n");
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
            head=deleteAtFirst(head);
            break;

            case 5:
            printf("Enter the index of the element ro be deleted:\n");
            scanf("%d",&i);
            head=deleteInBet(head,i);
            break;

            case 6:
            head=deleteAtEnd(head);
            break;

            case 7:
            show(head);
            break;

            case 8:
            exit(0);

            default:
            printf("Invalid choice!\n");
        }
    }
}
