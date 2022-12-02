#include<stdio.h>
#include<stdlib.h>
#define size 10
void insert_rear(int q[],int *r, int item)
{
    if(*r==size-1)
    printf("Queue overflow!\n");
    else
    {
        (*r)++;
        q[*r]=item;
    }
}
int delete_front(int q[],int *r, int *f)
{
    int del_item=-1;
    if(*f>*r)
    printf("Queue underflow!\n");
    else
    {
        del_item=q[*f];
        (*f)++;
    }
    return del_item;
}
void display(int q[],int *r, int *f)
{
    int i;
    if(*f>*r)
    printf("Queue is empty!\n");
    else
    {
        for(i=*f;i<=*r;i++)
        printf("Element %d is %d.\n",i+1,q[i]);
    }
}
void main()
{
    int q[size],data,c;
    int f=0;
    int r=-1;
    while(1)
    {
        printf("Enter 1 for inserting values.\nEnter 2 for deleting values.\nEnter 3 for displayig values.\nEnter 4 to exit.\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("Enter the value to be inserted:\n");
            scanf("%d",&data);
            insert_rear(q,&r,data);
            break;
            
            case 2:
            printf("The deleted element is %d.\n",delete_front(q,&r,&f));
            break;
            
            case 3:
            display(q,&r,&f);
            break;
            
            case 4:
            exit(0);
            
            default:
            printf("Enter a valid choice1\n");
            break;
        }
    }
}

