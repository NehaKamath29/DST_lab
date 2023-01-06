#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *head)
{
       int i=0;
      if(head==NULL)
    {
        printf("Nothing to display!\n");
        
    }
    else
    {
        struct Node *ptr=head;
     
        while(ptr!=NULL)
        {
            printf("Element %d is %d.\n",(i+1),ptr->data);
            ptr=ptr->next;
            i++;
        }
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
struct Node *sort(struct Node *head)
{
    int temp;
    if(head==NULL)
    {
        printf("No linked list!\n");
        return NULL;
    }
    else
    {
        struct Node *p=head;
        while(p->next!=NULL)
        {
            struct Node *q=p->next;
            while(q!=NULL)
            {
                if(p->data>q->data)
                {
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                }
                q=q->next;
            }
            p=p->next;
        }
    }
    return head;
}
void main()
{
    int n,i,data;
    struct Node *head=NULL;
    
    printf("Enter the number of terms you want to enter in the linked list:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter element %d to be inserted:\n",i);
        scanf("%d",&data);
        head=insertAtEnd(head,data);
    }
    head=sort(head);
    display(head);
}

