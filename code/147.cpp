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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* node=head;
        if(node==NULL) return node;
        ListNode* com=node->next;
        while(com!=NULL){
            if(com->val >=node->val){
                node=com;
                com=node->next;
            }else{
                node->next=com->next;
                ListNode* temp=head;
                ListNode* curr=NULL;
                while(temp!=node->next){
                    if(temp->val <= com->val){
                        curr=temp;
                        temp=temp->next;
                    }else{
                         com->next=temp;
                         if(curr==NULL){
                            head=com;
                        }else{
                            curr->next=com;
                        }
                        break;
                    }
                }
                com=node->next;
            }
        }
        return head;
    }
};
