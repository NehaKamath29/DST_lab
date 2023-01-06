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
struct Node *concatenate(struct Node *head1, struct Node*head2)
{
    
    struct Node *p=head1;
    if(head1==NULL && head2!=NULL)
    return head2;
    else if(head2==NULL && head1!=NULL)
    return head1;
    else if(head1==NULL && head2==NULL)
    {
        printf("Both the linked lists are empty to concatenate!\n"); 
        return NULL;
    }
    else
    {
        
        while(p->next!=NULL)
        {
            p=p->next;
        }
        
        p->next=head2;
        return head1;
    }
}
void main()
{
    int n,i,data;
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    printf("Enter the number of terms you want to enter in the first linked list:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter element %d to be inserted:\n",i);
        scanf("%d",&data);
        head1=insertAtEnd(head1,data);
    }
    printf("Enter the number of terms you want to enter in the second linked list:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter element %d to be inserted:\n",i);
        scanf("%d",&data);
        head2=insertAtEnd(head2,data);
    }
    head1=concatenate(head1,head2);
    display(head1);
}

