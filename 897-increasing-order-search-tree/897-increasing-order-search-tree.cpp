/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode *prevNode = NULL;
    
    TreeNode* increasingBST(TreeNode* root) 
    {
        if(!root) return NULL;
        
        root->right = increasingBST(root->right);
        
        if(prevNode)
            root->right = prevNode;
        
        TreeNode *temp = root->left;

        root->left = NULL;
        
        prevNode = root;
        
        increasingBST(temp);
        
        
        return prevNode;
    }
};