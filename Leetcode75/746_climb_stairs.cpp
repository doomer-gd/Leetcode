#include <iostream>
#include <vector>

class Solution
{
	public:
		int minCostClimbingStairs(std::vector<int>& cost);
};

int	Solution::minCostClimbingStairs(std::vector<int>& cost)
{
	int	size = cost.size();
	int	index = size - 3;

	while (index >= 0)
	{
		cost[index] += std::min(cost[index + 1], cost[index + 2]);
		index--;
	}
	return std::min(cost[0], cost[1]);
}

int	main()
{
	Solution	solve;

	std::vector<int>	vec1({10,15});
	std::vector<int>	vec2({1,100,1,1,1,100,1,1,100,100});
	std::vector<int>	vec3({10,10,10,10});
	int	result;

	result = solve.minCostClimbingStairs(vec1);
	std::cout << result << std::endl;
	result = solve.minCostClimbingStairs(vec2);
	std::cout << result << std::endl;
	result = solve.minCostClimbingStairs(vec3);
	std::cout << result << std::endl;
	return (0);
}