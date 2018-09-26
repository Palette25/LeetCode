/*
*  Recursive Poster Traversal of a Binary Tree
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)
            return result;
        if(root->left != NULL) postorderTraversal(root->left);
        if(root->right != NULL) postorderTraversal(root->right);
        result.push_back(root->val);
        return result;
    }
    
private:
   vector<int> result; 
};

/*
*  Iterative Poster Traversal of a Binary Tree
*/
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> store;
		while(!store.empty() || root != NULL) {
			if(root == NULL) {
				TreeNode* temp = store.top();
				store.pop();
				root = temp->right; //之后接着遍历右子树
			}else {
				result.insert(result.begin(), root->val);  //将节点值压入队列头部
				store.push(root);  //将父节点压栈，然后遍历左子树
				root = root->left; 
			}
		}
		return result;
	}
};