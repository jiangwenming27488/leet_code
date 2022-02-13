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
    int length(ListNode* head){
        int len=0;
        ListNode* node=head;
        while(node){
            len++;
            node=node->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev=nullptr;
        ListNode* node=head;
        for(int i=0;i<length(head)-n;++i){
            prev=node;
            node=node->next;
        }
        if(prev==nullptr){
            head=head->next;
        }else{
            prev->next=node->next;
        }
        return head;
    }
};