bool hasCycle(struct ListNode *head) 
{
    struct ListNode *p=head;
    struct ListNode *q=head;
   
    while(q->next!=NULL && q!=NULL)
    {
        p=p->next;
        q=q->next->next;
        if(p==q)
        return true;
    }
   return false;
}