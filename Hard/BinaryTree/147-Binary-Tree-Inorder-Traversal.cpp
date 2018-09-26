/*
*  Recursive Inorder Traversal of a Binary Tree
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if(root == NULL)
			return result;
		if(root->left != NULL) inorderTraversal(root->left);
		result.push_back(root->val);
		if(root->right != NULL) inorderTraversal(root->right);
		return result;
	}
private:
	vector<int> result;
};

/*
*  Iterative Inorder Traversal of a Binary Tree
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> store;
		while(!store.empty() || root != NULL) {
			if(root == NULL) {
				TreeNode* temp = store.top();
				store.pop();
				result.push_back(root->val);
				root = temp->right;
			}else {
				store.push(root);
				root = root->left;
			}
		}
	}
};