#include <vector>
#include <iostream>
#include <stack>

class Solution
{
	private:
		std::stack<int>					visitOrder;
		std::vector<bool>				isVisited;
		std::vector<std::vector<int>>	edges;
		int								result = 0;

		void	visitNode(int n);
	public:
		int minReorder(int n, std::vector<std::vector<int>>& connections);
};

int Solution::minReorder(int n, std::vector<std::vector<int>>& connections)
{
	edges = std::vector<std::vector<int>>(n);
	isVisited = std::vector<bool>(n, false);

	for (std::vector<int> connection : connections)
	{
		edges[connection[0]].push_back(-connection[1]);
		edges[connection[1]].push_back(connection[0]);
	}
	visitOrder.push(0);
	isVisited[0] = true;
	while (visitOrder.empty() == false)
		visitNode(visitOrder.top());
	return result;
}

void	Solution::visitNode(int i)
{
	visitOrder.pop();
	for (int nextNode : edges[i])
	{
		if (nextNode < 0)
		{
			nextNode = -nextNode;
			if (isVisited[nextNode] == false)
				result++;
		}
		if (isVisited[nextNode] == false)
		{
			visitOrder.push(nextNode);
			isVisited[nextNode] = true;
		}
	}
}


int	main()
{
	Solution	solve1;
	std::vector<std::vector<int>>	vec1{{0,1},{1,3},{2,3},{4,0},{4,5}};

	std::cout << solve1.minReorder(6, vec1) << std::endl;

	Solution	solve2;
	std::vector<std::vector<int>>	vec2{{1,0},{1,2},{3,2},{3,4}};

	std::cout << solve2.minReorder(5, vec2) << std::endl;

	Solution	solve3;
	std::vector<std::vector<int>>	vec3{{1,0},{2,1},{3,2},{4,3}};

	std::cout << solve3.minReorder(5, vec3) << std::endl;

	Solution	solve4;
	std::vector<std::vector<int>>	vec4{{0,1}};

	std::cout << solve4.minReorder(2, vec4) << std::endl;

	Solution	solve5;
	std::vector<std::vector<int>>	vec5{{0,1},{2,1},{3,1},{4,0}};

	std::cout << solve5.minReorder(5, vec5) << std::endl;
	return (0);
}