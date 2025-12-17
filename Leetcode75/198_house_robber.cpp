#include <iostream>
#include <vector>

class Solution {
	public:
		int rob(std::vector<int>& nums);
};

int Solution::rob(std::vector<int>& nums)
{
	int	size = nums.size();
	int	bestWithLast = 0;
	int	bestWithoutLast = 0;
	int	tempBest;

	if (size == 1)
		return nums[0];
	bestWithLast = nums[1];
	bestWithoutLast = nums[0];
	for (int i = 2; i < size; i++)
	{
		tempBest = bestWithoutLast;
		bestWithoutLast = std::max(bestWithLast, bestWithoutLast);
		bestWithLast = nums[i] + tempBest;
	}
	return std::max(bestWithLast, bestWithoutLast);
}

int	main()
{
	Solution	solve;

	std::vector<int>	vec1({9,9,3,1,3});
	std::vector<int>	vec2({1,2,3,1});
	std::vector<int>	vec3({2,7,9,3,1});
	std::vector<int>	vec4({9});
	std::vector<int>	vec5({9,5});
	int					result;

	result = solve.rob(vec1);
	std::cout << result << std::endl;
	result = solve.rob(vec2);
	std::cout << result << std::endl;
	result = solve.rob(vec3);
	std::cout << result << std::endl;
	result = solve.rob(vec4);
	std::cout << result << std::endl;
	result = solve.rob(vec5);
	std::cout << result << std::endl;
	return (0);
}