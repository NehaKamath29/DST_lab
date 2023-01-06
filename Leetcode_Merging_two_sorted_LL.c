//Leetcode problem: Merging two sorted listed lists

struct ListNode *sort(struct ListNode *head)
{
    int temp;
    if(head==NULL)
    {
        printf("No linked list!\n");
        return NULL;
    }
    else
    {
        struct ListNode *p=head;
        while(p->next!=NULL)
        {
            struct ListNode *q=p->next;
            while(q!=NULL)
            {
                if(p->val>q->val)
                {
                    temp=p->val;
                    p->val=q->val;
                    q->val=temp;
                }
                q=q->next;
            }
            p=p->next;
        }
    }
    return head;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode *head1,*head2;
    if(list1==NULL && list2!=NULL)
    return list2;
    else if(list2==NULL && list1!=NULL)
    return list1;
    else if(list1==NULL && list2==NULL)
    return NULL;
    else
    {
        
        struct ListNode *p=list1;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=list2;
        list1=sort(list1);
        return list1;
    }
}