struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#include <stdlib.h>
#include <stdbool.h>
#define LEFT 1
#define RIGHT 0

int	DiveDown(struct TreeNode* node, int currentLenght, bool isLeft, int maxLenght)
{
	int	resultLeft = 0;
	int	resultRight = 0;

	if (currentLenght > maxLenght)
		maxLenght = currentLenght;
	if (node->left != NULL)
		resultLeft = DiveDown(node->left, isLeft * currentLenght + 1, RIGHT, maxLenght);
	if (node->right != NULL)
		resultRight = DiveDown(node->right, !isLeft * currentLenght + 1, LEFT, maxLenght);
	if (resultLeft > maxLenght)
		maxLenght = resultLeft;
	if (resultRight > maxLenght)
		maxLenght = resultRight;
	return maxLenght;
}

int longestZigZag(struct TreeNode* root)
{
	int	result;

	if (root == NULL)
		return 0;
	result = DiveDown(root, 0, LEFT, 0);
	return result;
}