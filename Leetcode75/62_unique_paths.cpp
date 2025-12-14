#include <iostream>

class Solution {
public:
	int uniquePaths(int m, int n)
	{
		long		width;
		long		height;
		size_t		result = 1;

		width = std::min(m, n);
		height = std::max(m, n) - 1;
		for (int i = 1; i < width; i++)
			result = (result * (height + i)) / i;
		return result;
	}
};

int	main()
{
	Solution	solve;

	std::cout << solve.uniquePaths(13, 25) << std::endl;
	return (0);
}