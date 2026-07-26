/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *prev,*curr,*next;
        prev=NULL;
        curr=head;
        next=head->next;
        while(next)
        {
            curr->next=prev;
            prev=curr;
            curr=next;
            next=curr->next;
        }
        curr->next=prev;
        return curr;
    }
    void reorderList(ListNode* head) {
        ListNode *slow,*fast;
        slow=fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *tmp;
        ListNode *rev=reverseList(slow->next);
        slow->next=NULL;
        slow=head;
        while(slow && rev)
        {
            tmp=slow;
            slow=slow->next;
            tmp->next=rev;
            tmp=rev;
            rev=rev->next;
            tmp->next=slow;
        }
    }
};