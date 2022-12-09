#include<stdio.h>
#include<stdlib.h>
#define size 4
void insert_rear(int q[],int *r, int item, int *count)
{
    if(*count==size)
    printf("Queue overflow!\n");
    else
    {
        q[*r]=item;
        *r=((*r)+1)%size;
        (*count)=(*count)+1;
       
    }
}
int delete_front(int q[],int *r, int *f, int *count)
{
    int del_item=-1;
    if(*count==0)
    printf("Queue underflow!\n");
    else
    {
        del_item=q[(*f)];
        (*f)=((*f)+1)%size;
        (*count)=(*count)-1;
        
    return del_item;
}
void display(int q[],int *f, int *count)
{
    int i,temp;
    temp=*f;
    
    for(i=0;i<*count;i++)
    {
      printf("Element %d is %d.\n",i+1,q[temp]);
      temp=(temp+1)%size;
    }
}
void main()
{
    int q[size],data,c;
    int f=0;
    int r=0;
    int count=0;
    while(1)
    {
        printf("Enter 1 for inserting values.\nEnter 2 for deleting values.\nEnter 3 for displayig values.\nEnter 4 to exit.\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("Enter the value to be inserted:\n");
            scanf("%d",&data);
            insert_rear(q,&r,data,&count);
            break;
            
            case 2:
            printf("The deleted element is %d.\n",delete_front(q,&r,&f,&count));
            break;
            
            case 3:
            display(q,&f,&count);
            break;
            
            case 4:
            exit(0);
            
            default:
            printf("Enter a valid choice1\n");
            break;
        }
    }
}
