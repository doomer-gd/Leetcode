#include <iostream>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stack>

enum NextTurn
{
	LEFT,
	RIGHT
};

typedef std::pair<TreeNode*, NextTurn>	NodeItem;
typedef std::stack<NodeItem>			TreeStack;

class Solution
{
	private:
		TreeStack	nodeRoute1;
		TreeStack	nodeRoute2;
		TreeNode*	GetNextLeaf(TreeStack& nodeStack);
	public:
		bool leafSimilar(TreeNode* root1, TreeNode* root2);
};

bool	Solution::leafSimilar(TreeNode* root1, TreeNode* root2)
{
	TreeNode*	leaf1;
	TreeNode*	leaf2;

	nodeRoute1.push(NodeItem(root1, LEFT));
	nodeRoute2.push(NodeItem(root2, LEFT));
	leaf1 = GetNextLeaf(nodeRoute1);
	leaf2 = GetNextLeaf(nodeRoute2);
	while (leaf1 != nullptr && leaf2 != nullptr)
	{
		if ((leaf1 == nullptr) || (leaf2 == nullptr))
			break;
		if (leaf1->val != leaf2->val)
			return false;
		leaf1 = GetNextLeaf(nodeRoute1);
		leaf2 = GetNextLeaf(nodeRoute2);
	};
	return (leaf1 == nullptr) && (leaf2 == nullptr);
}

TreeNode*	Solution::GetNextLeaf(TreeStack& nodeStack)
{
	TreeNode*	root = nullptr;

	while (!nodeStack.empty())
	{
		root = nodeStack.top().first;
		if (nodeStack.top().second == LEFT)
		{
			nodeStack.top().second = RIGHT;
			if (root->left != nullptr)
			{
				nodeStack.push(NodeItem(root->left, LEFT));
				continue;
			}
		}
		nodeStack.pop();
		if (root->right != nullptr)
			nodeStack.push(NodeItem(root->right, LEFT));
		else if (root->left == nullptr)
			return root;
	}
	return nullptr;
}

int main()
{
	{
		Solution	solve;
		TreeNode	root1(1);
		TreeNode	left1(2);
		TreeNode	right1(3);
		root1.left = &left1;
		root1.right = &right1;

		TreeNode	root2(1);
		TreeNode	left2(2);
		TreeNode	right2(3);
		root2.left = &left2;
		root2.right = &right2;	
		std::cout << solve.leafSimilar(&root1, &root2) << std::endl;
	}
	{
		Solution	solve;
		TreeNode	root1(1);
		TreeNode	root2(2);
		std::cout << solve.leafSimilar(&root1, &root2) << std::endl;
	}
	{
		Solution	solve;
		TreeNode	root1(1);
		TreeNode	left1(1);
		TreeNode	root2(2);
		TreeNode	right2(1);
		TreeNode	left2(1);

		root1.left = &left1;
		root2.right = &right2;
		root2.left = &left2;
		std::cout << solve.leafSimilar(&root1, &root2) << std::endl;
	}
	return 0;
}