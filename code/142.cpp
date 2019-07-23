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
    ListNode *detectCycle(ListNode *head) {
        ListNode* node=head;
        while(node!=NULL){
            pos=m_set.find(node);
            if(pos!=m_set.end()){
                return (*pos);
            }
            m_set.insert(node);
            node=node->next;
        }
        return node;
    }
private:
    set<ListNode*> m_set;
    set<ListNode*>::iterator pos;
};
