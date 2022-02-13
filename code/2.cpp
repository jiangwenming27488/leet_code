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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result=nullptr;
        ListNode* next=nullptr;
        int number=0;
        while(l1!=nullptr || l2!=nullptr){
            if(l1!=nullptr) {
                number+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                number+=l2->val;
                l2=l2->next;
            }
            ListNode* tmp=new ListNode(number%10);
            number/=10;
            if(result==nullptr){
                result=tmp;
                next=tmp;
            }else{
                next->next=tmp;
                next=next->next;
            }
        }
        if(number>0){
            next->next=new ListNode(number);
        }
        return result;
    }
};