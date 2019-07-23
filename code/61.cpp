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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* node=head;
        if(node){
            int count=0;
            while(node->next){
                count+=1;
                node=node->next;
            }
            count+=1;
            k=k%count;
            k=count-k;
            node->next=head;
            node=head;
            while(k--){
                head=node;
                node=node->next;
            }
            head->next=NULL;
        }
        return node;
    }
};
