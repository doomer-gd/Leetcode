#include <iostream>
#include <vector>

class Solution {
	private:
		int numElements;
		std::vector<int>	ans;
		void	FillIn(int& indMain, int currentPower);
	public:
		std::vector<int> countBits(int n)
		{
			int	indexMain = 2;
			int	currentPower = 1;

			ans = std::vector<int>(n + 1);
			ans[0] = 0;
			if (n == 0)
				return ans;
			ans[1] = 1;
			numElements = n + 1;
			while (indexMain < numElements)
			{
				FillIn(indexMain, currentPower);
				currentPower *= 2;
			}
			return ans;
		}
};


void	Solution::FillIn(int& indMain, int currentPower)
{
	int nextRepeat;

	nextRepeat = std::min(indMain + currentPower, numElements);
	for (; indMain < nextRepeat; indMain++)
		ans[indMain] = ans[indMain - currentPower];
	nextRepeat = std::min(nextRepeat + currentPower, numElements);
	for (; indMain < nextRepeat; indMain++)
		ans[indMain] = ans[indMain - currentPower] + 1;
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

	PrintVector(solve.countBits(32));
	PrintVector(solve.countBits(2));
	PrintVector(solve.countBits(15));
	PrintVector(solve.countBits(0));
	return (0);
}