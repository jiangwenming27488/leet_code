/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* second;
        ListNode* first=head;
        while(first!=NULL){
            second=first->next;
            if(second!=NULL){
                first->next=second->next;
                second->next=first;
                if(pre){
                    pre->next=second;
                }else{
                    head=second;
                }
                pre=first;
            }
            first=first->next;
        }
        return head;
    }
};
