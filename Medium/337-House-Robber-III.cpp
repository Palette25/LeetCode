/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        int left_val = 0, right_val = 0;
        return recursive_rob(root, left_val, right_val);
    }
    
    int recursive_rob(TreeNode* root, int& left_val, int& right_val){
        if(root == NULL) return 0;
        int ll_val = 0, lr_val = 0, rl_val = 0, rr_val = 0;
        left_val = recursive_rob(root->left, ll_val, lr_val);
        right_val = recursive_rob(root->right, rl_val, rr_val);
        return max(left_val + right_val, root->val + ll_val + lr_val + rl_val + rr_val);
    }
};