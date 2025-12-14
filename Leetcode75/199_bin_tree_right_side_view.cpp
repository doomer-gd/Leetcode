
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <iostream>

class Solution {
	private:
		std::vector<std::string>	maxLevels;
		std::vector<int>			visibleVals;
		int					maxDepth = -1;
		void	DepthSearch(TreeNode* node, int depth, std::string level);
		void	AddDepth(TreeNode* node, std::string level);
	public:
		std::vector<int> rightSideView(TreeNode* root);
};

std::vector<int>	Solution::rightSideView(TreeNode* root)
{
	if (root == NULL)
		return std::vector<int>();
	DepthSearch(root, 0, "");
	return visibleVals;
}

void	Solution::DepthSearch(TreeNode* node, int depth, std::string level)
{
	if (depth > maxDepth)
		AddDepth(node, level);
	if (level.compare(maxLevels[depth]) > 0)
	{
		maxLevels[depth] = level;
		visibleVals[depth] = node->val;
	}
	if (node->left != NULL)
		DepthSearch(node->left, depth + 1, level + "0");
	if (node->right != NULL)
		DepthSearch(node->right, depth + 1, level + "1");
}

void	Solution::AddDepth(TreeNode* node, std::string level)
{
	maxDepth++;
	maxLevels.push_back(level);
	visibleVals.push_back(node->val);
}

int	main()
{
	std::string	a("000");
	std::string	b("111");

	std::cout << b.compare(a) << std::endl;
}