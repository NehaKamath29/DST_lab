#include <stdio.h>
#include<stdlib.h>
#define size 10
void push(int st[],int *top,int data)
{
    if(*top==size-1)
    printf("Stack overflow condition!\n");
    else
    {
     (*top)++;
    st[*top]=data;
    
    }
}
int pop(int st[], int *top)
{
    int n;
    if(*top==-1)
    printf("Stack underflow condition!\n");
    
    else
    {
        n=st[*top];
        (*top)--;
        return n;
    }
}
void display(int st[], int *top)
{
    int i;
    if(*top==-1)
    printf("No values to display.\n");
    else
    {
        for(i=0;i<=*top;i++)
        {
            printf("Element %d is %d.\n",i+1,st[i]);
        }
    }
}
void main()
{
    int st[size],top=-1,data,c;
    while(1)
    {
        printf("Enter 1 for inserting values.\nEnter 2 for deleting values.\nEnter 3 for displayig values.\nEnter 4 to exit.\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("Enter the value to be inserted:\n");
            scanf("%d",&data);
            push(st,&top,data);
            break;
            
            case 2:
            printf("The popped element is %d.\n",pop(st,&top));
            break;
            
            case 3:
            display(st,&top);
            break;
            
            case 4:
            exit(0);
            
            default:
            printf("Enter a valid choice1\n");
            break;
        }
    }
}

