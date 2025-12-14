#include <iostream>
#include <algorithm>

class Solution {
public:
	bool closeStrings(std::string word1, std::string word2)
	{
		if (word1.size() != word2.size())
			return false;
		
		int	freqs[2][26] = {0};

		for (char c: word1)
			freqs[0][c - 'a']++;
		for (char c: word2)
			freqs[1][c - 'a']++;
		for (int i = 0;i < 26; i++)
		{
			if ((freqs[0][i] == 0) ^ (freqs[1][i] == 0))
				return false;
		}
		std::sort(&freqs[0][0], (&freqs[0][25] + 1));
		std::sort(&freqs[1][0], (&freqs[1][25] + 1));
		for (int i = 0;i < 26; i++)
		{
			if ((freqs[0][i] != freqs[1][i]))
				return false;
		}
		return true;
	}
};

int	main()
{
	Solution	solve;

	std::string	s1 = std::string("aaacbz");
	std::string	s2 = std::string("bbbacz");
	std::cout << solve.closeStrings(s1, s2) << std::endl;
	return (0);
}