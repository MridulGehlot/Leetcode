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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int left,prev,maxi,mini,lcnt,cnt;
        cnt=0;
        left=-1;
        maxi=INT_MIN;
        mini=INT_MAX;
        prev=-1;
        lcnt=-1;
        while(head->next)
        {
            if(prev!=-1) 
            {
                if((head->val<prev && head->val<head->next->val) || (head->val>prev && head->val>head->next->val)) //critical point
                {
                    if(left==-1) left=cnt;
                    if(lcnt!=-1) 
                    {
                        mini=min(mini,cnt-lcnt);
                    }
                    lcnt=cnt;
                }
            }
            prev=head->val;
            head=head->next;
            ++cnt;
        }
        maxi=lcnt-left;
        if(lcnt==-1 || mini==INT_MAX || maxi==INT_MIN) return {-1,-1};
        return {mini,maxi};
    }
};