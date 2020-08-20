class Solution {
public:
    
    void mergeList(ListNode* p,ListNode* q) {
         ListNode* t;
        while(q)
        {
            t=p->next;
            p->next=q;
            q=q->next;
            p=p->next;
            p->next=t;
            p=p->next;
        }
    }
    
    ListNode* reverse(ListNode* q) {
        ListNode* prev=NULL;
        ListNode* curr=q;
        while(curr!=NULL) {
            ListNode* node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=node;
        }
        return prev;
    }
    
    ListNode* findMid(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=NULL;
        return mid;
    }
    
    void reorderList(ListNode* head) {
        if(!head) {
            return ;
        }
        ListNode* p=head;
        ListNode* q=findMid(head);
        q=reverse(q);
        mergeList(p,q);
    }
};
