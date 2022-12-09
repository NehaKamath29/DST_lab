#define size 50
void push(char st[],int *top,char data)
{
    if(*top==size-1)
    printf("Stack overflow condition!\n");
    else
    {
     (*top)++;
    st[*top]=data;
    
    }
}
int pop(char st[], int *top)
{
    char n;
    if(*top==-1)
    printf("Stack underflow condition!\n");
    
    else
    {
        n=st[*top];
        (*top)--;
        
    }
    return n;
}
int isEmpty(char st[],int *top)
{
   if(*top==-1)
   return 1;
   else 
   return 0;
}
int isFull(char st[],int *top)
{
   if(*top==size-1) 
   return 1;
   else
   return 0;
}

int scoreOfParentheses(char * s)
{
   char st[50];
   int top=-1;

    int i,count=0,rem;
    
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='(')
        push(st,&top,0);
        else
        {
            if(s[i]==')')
            {
                if(s[i-1]==')')
                {
                   char c= pop(st,&top);
                }
                else
                {
                    if(top+1>1)
                    {
                        count+=pow(2,top);
                        char v= pop(st,&top);
                    }
                    else
                    {
                        count++;
                        char ch=pop(st,&top);
                    }
                }
            }
        }
    }
    return count;
}
            