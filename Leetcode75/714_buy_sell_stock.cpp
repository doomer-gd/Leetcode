#include <iostream>
#include <vector>

class Solution
{
	private:
		long	bestHeld;
		long	bestFree;
		int	size;
	public:
		int maxProfit(std::vector<int>& prices, int fee);
};

int	Solution::maxProfit(std::vector<int>& prices, int fee)
{
	long	buy = 0;
	long	sell = 0;

	size = prices.size();
	if (size <= 1)
		return 0;
	bestHeld = - std::min(prices[0], prices[1]);
	if (prices[1] > prices[0])
		buy = prices[1] - prices[0] - fee;
	bestFree = 0;
	if (buy > 0)
		bestFree = buy;
	for (int i = 2; i < size; i++)
	{
		sell = bestHeld + prices[i] - fee;
		sell = std::max(bestFree, sell);
		buy = bestFree - prices[i];
		buy = std::max(bestHeld, buy);
		bestFree = sell;
		bestHeld = buy;
	}
	return bestFree;
}

int	main()
{
	Solution	solve;

	std::vector<int>	vec1({1,3,2,8,4,9});
	std::vector<int>	vec2({1,3,7,5,10,3});
	std::vector<int>	vec3({2,7,9,1,3,0,4,10});
	std::vector<int>	vec4({9});
	std::vector<int>	vec5({5,9});
	int					result;

	result = solve.maxProfit(vec1, 2);
	std::cout << result << std::endl;
	result = solve.maxProfit(vec2, 3);
	std::cout << result << std::endl;
	result = solve.maxProfit(vec3, 1);
	std::cout << result << std::endl;
	result = solve.maxProfit(vec4, 1);
	std::cout << result << std::endl;
	result = solve.maxProfit(vec5, 3);
	std::cout << result << std::endl;
	return (0);
}