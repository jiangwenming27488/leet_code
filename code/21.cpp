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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev=nullptr;
        ListNode* head=list1;
        while(list1 && list2){
            if(list1->val>list2->val){
                ListNode* next=list2->next;
                if(prev==nullptr){
                    head=list2;
                }else{
                    prev->next=list2;
                }
                list2->next=list1;
                prev=list2;
                list2=next;
            }else{
                prev=list1;
                list1=list1->next;
            }
        }
        if(list2){
            if(prev==nullptr){
                head=list2;
            }else{
                prev->next=list2;
            }
        }
        return head;
    }
};