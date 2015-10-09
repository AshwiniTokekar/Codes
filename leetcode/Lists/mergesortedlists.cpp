 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode*newlist=NULL;
        ListNode *temp,*curnode;
        if(l1==NULL&&l2==NULL)
            return NULL;
        else if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                temp=new ListNode(l1->val);
              //  temp->val=l1->val;
                if(newlist==NULL)
                {
                   newlist=temp;
                   curnode=newlist;
             //      cout<<curnode->val;
                }   
                else
                {
                    curnode->next=temp;
                    curnode=curnode->next;
                }
                   
                l1=l1->next;
            }
            else 
            {
                temp=new ListNode(l2->val);
               // temp->val=l2->val;
                if(newlist==NULL)
                {
                   newlist=temp;
                   curnode=newlist;
                }   
                else
                {
                    curnode->next=temp;
                    curnode=curnode->next;
                }
                   
                l2=l2->next;
            }
        }
        if(l1==NULL)
        {
            curnode->next=l2;
        }
        else
           curnode->next=l1;
    return newlist;       
    }