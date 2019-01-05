/*
*definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node=head;
        ListNode* list=NULL;
        int number=n;
        while(node){
            ListNode* temp=node;
            number=n;
            while(number--){
                temp=temp->next;
            }
            if(temp==NULL){
                if(list==NULL){
                    head=head->next;
                }else{
                    list->next=node->next;
                }
                node->next=NULL;
                free(node);
                break;
            }else{
                list=node;
                node=node->next;
            }
        }
        return head;
    }
};
