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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=NULL;
        ListNode* index=head;
        ListNode* last=index;
        ListNode* start=index;
        while(index!=NULL){
            start=index->next;
            last=index;
            while(start!=NULL){
                if(start->val==index->val){
                    last=start;
                    start=start->next;
                }else break;
            }
            if(start!=index->next){
                if(index==head){
                    head=start;
                    index=start;
                }else{
                    curr->next=start;
                    index=start;
                }
            }else{
                curr=index;
                index=index->next;
            }
        }
        return head;
    }
};
