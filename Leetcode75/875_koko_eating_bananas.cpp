#include <iostream>
#include <vector>

class Solution
{
	private:
		int	minSpeed;
		int	maxSpeed = 0;
		int	currentSpeed;
		int	timeLimit;
		bool	IsFastEnough(std::vector<int>& piles, int speed);
	public:
		int minEatingSpeed(std::vector<int>& piles, int h);
};

int	Solution::minEatingSpeed(std::vector<int>& piles, int h)
{
	long long	total = 0;
	timeLimit = h;

	for (int pile: piles)
	{
		total += pile;
		if (pile > maxSpeed)
			maxSpeed = pile;
	}
	if (piles.size() == (size_t)h)
		return maxSpeed;
	minSpeed = std::max(total / h, 1ll);
	while (minSpeed < (maxSpeed - 1))
	{
		currentSpeed = minSpeed + (maxSpeed - minSpeed) / 2;
		if (IsFastEnough(piles, currentSpeed))
			maxSpeed = currentSpeed;
		else
			minSpeed = currentSpeed;
	}
	if (IsFastEnough(piles, minSpeed))
		return minSpeed;
	return maxSpeed;
}

bool	Solution::IsFastEnough(std::vector<int>& piles, int speed)
{
	int	timeTotal = 0;

	for (int pile: piles)
		timeTotal += pile / speed + (pile % speed > 0);
	return timeTotal <= timeLimit;
}

int	main()
{
	{
		Solution	solve;
		std::vector<int>	vec({3,6,7,11});
		std::cout << solve.minEatingSpeed(vec, 8) << std::endl;
	}
	{
		Solution	solve;
		std::vector<int>	vec({30,11,23,4,20});
		std::cout << solve.minEatingSpeed(vec, 5) << std::endl;
	}
	{
		Solution	solve;
		std::vector<int>	vec({30,11,23,4,20});
		std::cout << solve.minEatingSpeed(vec, 6) << std::endl;
	}
	{
		Solution	solve;
		std::vector<int>	vec({2,1,7});
		std::cout << solve.minEatingSpeed(vec, 10) << std::endl;
	}
	{
		Solution	solve;
		std::vector<int>	vec({10});
		std::cout << solve.minEatingSpeed(vec, 10) << std::endl;
	}
	return (0);
}