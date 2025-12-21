#include <iostream>
#include <vector>

class Solution {
	private:
		std::vector<int>	bestPrevLetter;
		int					lenght1;
		int					lenght2;
		int					allTimeBest = 0;
	public:
		int		longestCommonSubsequence(std::string text1, std::string text2);
};


int	Solution::longestCommonSubsequence(std::string text1, std::string text2)
{	
	int	currentBest = 0;
	int	prevBest;

	lenght1 = text1.size();
	lenght2 = text2.size();
	bestPrevLetter = std::vector<int>(lenght2, 0);
	currentBest = 0;
	for (int i = 0; i < lenght1; i++)
	{
		currentBest = std::max((int)(text1[i] == text2[0]), bestPrevLetter[0]);
		bestPrevLetter[0] = currentBest;
		for (int j = 1; j < lenght2; j++)
		{
			prevBest = currentBest;
			if (text1[i] == text2[j])
				currentBest = bestPrevLetter[j - 1] + 1;
			else
				currentBest = std::max(prevBest, bestPrevLetter[j]);
			bestPrevLetter[j - 1] = prevBest;
		}
		if (currentBest > allTimeBest)
			allTimeBest = currentBest;
	}
	return allTimeBest;
}

int	main()
{
	Solution	solve;

	char	test2[30] = "abc";
	char	test1[30] = "accc";
	
	std::cout << solve.longestCommonSubsequence(test1, test2) << std::endl;
	return (0);
}