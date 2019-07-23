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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* last1=NULL;
        ListNode* node1=l1;
        ListNode* last2=NULL;
        ListNode* node2=l2;
        while(node2!=NULL && node1!=NULL){
            last2=node2->next;
            if(node2->val<=node1->val){
                node2->next=node1;
                if(last1==NULL){
                    l1=node2;
                }else{
                    last1->next=node2;
                }
                last1=node2;
                node2=last2;
            }else{
                last1=node1;
                node1=node1->next;
            }
        }
        if(node2!=NULL){
            if(last1!=NULL)
                last1->next=node2;
            else return l2;
        }
        return l1;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(size==0) return NULL;
        for(int index=1;index<lists.size();++index){
            lists[0]=mergeTwoLists(lists[0],lists[index]);
        }
        return lists[0];
    }
};
