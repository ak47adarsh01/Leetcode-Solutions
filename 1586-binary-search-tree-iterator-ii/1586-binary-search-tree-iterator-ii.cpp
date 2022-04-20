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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
     
        while(root){
            inStack_.push(root);            
            root = root->left;
        }
    }
    
    bool hasNext() {
        if(inStack_.size() > 0)
            return true;
        
        if(currIter_ == --seq_.end())
            return false;
        
        return true;
    }
    
    int next() {
        if((seq_.size() > 0) && !(currIter_ == --seq_.end())){
            ++currIter_;
            return *currIter_;
        }
        
        TreeNode* top = inStack_.top();
        inStack_.pop();
        TreeNode* node = top->right;
        
        while(node){
            inStack_.push(node);
            node = node->left;
        }
        seq_.push_back(top->val);
        currIter_ = --seq_.end();
       
        return top->val;
    }
    
    bool hasPrev() {
       if(seq_.size() == 0 || currIter_ == seq_.begin())
           return false;
        
        return true;
    }
    
    int prev() {
        --currIter_;
        return *currIter_;
        
    }
    private:
    list<int> seq_;
    stack<TreeNode*> inStack_;
    list<int>::iterator currIter_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */