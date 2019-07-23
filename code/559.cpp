/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL) return 0;
        int max_ele=1;
        for(Node* &element:root->children){
            max_ele=max(maxDepth(element)+1,max_ele);
        }
        return max_ele;
    }
};
