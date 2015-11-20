#include <bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
};
bool comparelists(ListNode *head1,ListNode *head2)
    {
        while(head1!=NULL&&head2!=NULL)
        {
            if(head1->val!=head2->val)
            {
            	cout<<head1->val<<" "<<head2->val<<"\n";
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        if(head1==NULL&&head2==NULL)
            return true;
        return false;
    }

void reverse(ListNode **head)
    {
        ListNode *cur=*head;
        ListNode *prev=NULL;
        ListNode *next;
        while(cur!=NULL)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        *head=prev;
    }

bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        
        ListNode *fast=head,*slow=head,*prev=head;
        ListNode *mid=NULL,*second_half;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        if(fast!=NULL)
        {
            mid=slow;
            slow=slow->next;
        }
        second_half=slow;
        prev->next=NULL;
      //  cout<<"iisdi\n";
        reverse(&second_half);
      //  cout<<"reverse\n";
        ListNode *temp=second_half;
        while(temp!=NULL)
        {
        //	cout<<"In while\n";
        //	cout<<temp->val<<"\n";
        	temp=temp->next;
        }
        bool res=comparelists(head,second_half);
    //    cout<<second_half->val<<"\n";
        
  //      cout<<"Comparison done\n";
        reverse(&second_half); 

        if (mid != NULL)
         {
            prev->next = mid;
            mid->next = second_half;
         }
         else
            prev->next = second_half;
    
    return res;
        
    }

int main()
{
	ListNode *head=NULL,*temp;
	head=new ListNode;
	head->val=1;
	head->next=NULL;
	temp=new ListNode;
	temp->val=2;
	temp->next=NULL;
	head->next=temp;
	temp=NULL;
	temp=new ListNode;
	temp->val=2;
	temp->next=NULL;
	head->next->next=temp;
	temp=NULL;
	temp=new ListNode;
	temp->val=1;
	temp->next=NULL;
	head->next->next->next=temp;
	bool res=isPalindrome(head);//<<"\n";
	cout<<res<<"\n";
	return 0;
}