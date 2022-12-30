#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *top)
{
    int i;
    struct Node *ptr=top;
    i=0;
    if(top==NULL)
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
struct Node *push(struct Node *top,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    if(top==NULL)
    {
        top=ptr;
        return top;
    }
    else
    {
    
    ptr->next=top;
    top=ptr;
    return top;
    }
}
struct Node *pop(struct Node *top)
{
    if(top==NULL)
    {
        printf("Nothing to delete, the stack is empty!\n");
        return NULL;
    }
    else
    {
    int del_item=-1;
    struct Node *p=top;
    printf("The popped element is %d.\n",top->data);
    top=top->next;
    free(p);
    
    return top;
    }
}
void main()
{
    struct Node *top=NULL;
    int c,data;
    while(1)
    {
        printf("Enter 1 to push values into the stack.\nEnter 2 to pop values from the stack.\nEnter 3 to display.\nEnter 4 to exit.\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("Enter the value to be pushed:\n");
            scanf("%d",&data);
            top=push(top,data);
            break;
            
            case 2:
            top=pop(top);
            break;
            
            case 3:
            display(top);
            break;
            
            case 4:
            exit(0);
            
            default:
            printf("Invalid choice!\n");
        }
    }
}
            