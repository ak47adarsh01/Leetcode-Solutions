class Solution {
public:
    TreeNode* ans;
    void help(TreeNode* root, int val){
        if(root == NULL)
            return;
        if(root->val == val){
            ans = root;
            return;
        }
        if(val < root->val)
        help(root->left, val);
        else
        help(root->right, val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        help(root, val);
        return ans;
    }
};