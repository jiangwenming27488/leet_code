/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* node1_head=NULL;
        ListNode* node1=head;
        int temp=m;
        while(--m){
            node1_head=node1;
            node1=node1->next;
        }
        ListNode* node2_head=node1;
        ListNode* node2=node1->next;
        n-=temp;
        ListNode* cr=node2;
        while(n--){
            cr=node2->next;
            node2->next=node2_head;
            node2_head=node2;
            node2=cr;
        }
        if(node1_head!=NULL)
            node1_head->next=node2_head;
        else head=node2_head;
        node1->next=node2;
        return head;
        
    }
};
