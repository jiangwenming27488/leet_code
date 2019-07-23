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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
        temp->next=NULL;
        temp->val=-1;
        ListNode* result=temp;
        int current=0;
        while(l1!=NULL || l2!=NULL){
            if(l1==NULL) current=l2->val+current;
            else if(l2==NULL) current=l1->val+current;
            else 
                current=l1->val+l2->val+current;
            if(temp->val==-1){
                temp->val=current%10;
            }else{
                ListNode* node=(ListNode*)malloc(sizeof(ListNode));
                node->next=NULL;
                node->val=current%10;
                temp->next=node;
                temp=node;
            }
            current/=10;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        if(current!=0){
            ListNode* node=(ListNode*)malloc(sizeof(ListNode));
            node->val=current;
            node->next=NULL;
            temp->next=node;
        }
        return result;
    }
};
