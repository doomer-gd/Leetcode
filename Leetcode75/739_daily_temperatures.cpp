#include <iostream>
#include <vector>
#include <stack>

class Solution {
	private:
		std::stack<int>	pastTemps;
		int	size;
	public:
		std::vector<int> dailyTemperatures(std::vector<int>& temperatures);
};

std::vector<int>	Solution::dailyTemperatures(std::vector<int>& temperatures)
{
	std::vector<int>	answer(temperatures.size(), 0);
	size = temperatures.size();

	pastTemps.push(0);
	for (int current = 1; current < size; current++)
	{
		while (!pastTemps.empty() && temperatures[pastTemps.top()] < temperatures[current])
		{
			answer[pastTemps.top()] = current - pastTemps.top();
			pastTemps.pop();
		}
		pastTemps.push(current);
	}
	return answer;
}

template <class T>
void	PrintVector(std::vector<T>	vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int	main()
{
	Solution	solve;

	// std::vector<int>	vec1({73,74,75,71,69,72,76,73});
	// std::vector<int>	vec2({73,74,75,71,69,72,76,73});
	std::vector<int>	vec3({30});
	// std::vector<int>	result1;
	// std::vector<int>	result2;
	std::vector<int>	result3;

	// result1 = solve.dailyTemperatures(vec1);
	// PrintVector(result1);
	// result2 = solve.dailyTemperatures(vec2);
	// PrintVector(result2);
	result3 = solve.dailyTemperatures(vec3);
	PrintVector(result3);
	return (0);
}