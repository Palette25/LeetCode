/*
*  Recursive Preorder Traversal of a Binary Tree
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if(root == NULL)
			return result;
		result.push_back(root->val);
		if(root->left != NULL) preorderTraversal(root->left);
		if(root->right != NULL) preorderTraversal(root->right);
		return result;
	}
private:
	vector<int> result;
};

/*
*  Iterative Preorder Traversal of a Binary Tree
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> store;
		while(!store.empty() || root != NULL) {
			if(root == NULL) {
				TreeNode* temp = store.top();
				store.pop();
				root = temp->right;
			}else {
				result.push_back(root->val);  //在父节点往左子树开始遍历前，将父节点值推入result尾部
				store.push(root);
				root = root->left;
			}
		}
	}
};