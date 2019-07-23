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
    ListNode* reverse(ListNode* head){
        ListNode* temp=NULL;
        ListNode* curr=head;
        ListNode* first=NULL;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=first;
            first=curr;
            curr=temp;
        }
        return first;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL) return;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        slow=reverse(fast);
        ListNode* temp=NULL;
        ListNode* res=head;
        while(res!=NULL && slow!=NULL){
            temp=slow->next;
            slow->next=res->next;
            res->next=slow;
            res=slow->next;
            slow=temp;
        }
    }
};
