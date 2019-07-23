class Solution {
public:
    vector<int> _vec;
    stack<TreeNode*> s;
    vector<int> preorderTraversal(TreeNode* root) {
	    s.push(root);
	    TreeNode* p = NULL;
	    while (!s.empty()) {
		    p = s.top();
            s.pop();
		    if (p != NULL) {
			    _vec.emplace_back(p->val);
			    s.push(p->right);
			    s.push(p->left);
            }
		}
	    return _vec;
    }
};
