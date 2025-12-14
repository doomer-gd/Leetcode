#include <vector>
#include <iostream>
#include <deque>

class Solution
{
	private:
		std::deque<int>		order;
		std::vector<int>	result;
		bool	CollideStack(int asteroid);
	public:
		std::vector<int> asteroidCollision(std::vector<int>& asteroids);
};

std::vector<int> Solution::asteroidCollision(std::vector<int>& asteroids)
{
	for (int asteroid: asteroids)
	{
		if (asteroid > 0)
			order.push_back(asteroid);
		else if (CollideStack(asteroid))
			result.push_back(asteroid);
	}
	if (!order.empty())
		result.insert(result.end(),order.begin(), order.end());
	return result;
}

bool	Solution::CollideStack(int asteroid)
{
	bool	isAlive = true;

	while (!order.empty() && isAlive)
	{
		if (order.back() > -asteroid)
			isAlive = false;
		else if (order.back() < -asteroid)
			order.pop_back();
		else
		{
			isAlive = false;
			order.pop_back();
		}
	}
	return isAlive;
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

	std::vector<int>	vec({100, -90, 20, -20, 1, 2, 3, -110});
	std::vector<int>	result;

	result = solve.asteroidCollision(vec);
	PrintVector(result);
	return (0);
}