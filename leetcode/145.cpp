class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        vector<int> l = this->postorderTraversal(root->left);
        vector<int> r = this->postorderTraversal(root->right);
        result.insert(result.end(), l.begin(), l.end());
        result.insert(result.end(), r.begin(), r.end());
        result.push_back(root->val);
        return result;
    }
};