struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#include <stdlib.h>

struct TreeNode* searchBST(struct TreeNode* root, int val)
{
	while ((root != NULL))
	{
		if (root->val == val)
			return root;
		if (root->val > val)
			root = root->left;
		else
			root = root->right;
	}
	return NULL;
}