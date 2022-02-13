class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = traverse(root);
        return *max_element(res.begin(), res.end());
    }
    vector<int> traverse(TreeNode* root) {
        vector<int> res = {0,0};
        if (root == NULL) {
            return res;
        }
        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);
        res[0] = root->val + left[1] + right[1]; // with root
        res[1] = *max_element(left.begin(), left.end()) + *max_element(right.begin(), right.end()); // without root
        return res;
    }
};