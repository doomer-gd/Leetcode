#include <iostream>
#include <vector>
#include <map>

class Solution
{
	private:
		std::map<std::vector<int>, int>	rows;
		int		size;

		void	copyColumn(std::vector<std::vector<int>>& grid, std::vector<int>&column, int index);
	public:
		int	equalPairs(std::vector<std::vector<int>>& grid);
};

int	Solution::equalPairs(std::vector<std::vector<int>>& grid)
{
	std::map<std::vector<int>, int>::iterator	find;
	int	totalEquals = 0;
	size = grid.size();
	std::vector<int>	column(size);
	for (int i = 0; i < size; i++)
		rows[grid[i]]++;
	for (int i = 0; i < size; i++)
	{
		copyColumn(grid, column, i);
		find = rows.find(column);
		if (find != rows.end())
			totalEquals += (*find).second;
	}
	return totalEquals;
}

void	Solution::copyColumn(std::vector<std::vector<int>>& grid, std::vector<int>& column, int index)
{
	for (int i = 0; i < size; i++)
		column[i] = grid[i][index];
}

int	main()
{
	{
		Solution	solve;
		std::vector<std::vector<int>>	vec({{3,2,1},
											{1,7,6},
											{2,7,7}});
		std::cout << solve.equalPairs(vec) << std::endl;
	}
	{
		Solution	solve;
		std::vector<std::vector<int>>	vec({{3,1,2,2},
											{1,4,4,5},
											{2,4,2,2},
											{2,4,2,2}});
		std::cout << solve.equalPairs(vec) << std::endl;
	}
	{
		Solution	solve;
		std::vector<std::vector<int>>	vec({{1,1,1},
											{1,1,1},
											{1,1,1}});
		std::cout << solve.equalPairs(vec) << std::endl;
	}
	{
		Solution	solve;
		std::vector<std::vector<int>>	vec({{1,2,3},
											{2,1,3},
											{3,3,1}});
		std::cout << solve.equalPairs(vec) << std::endl;
	}
	{
		Solution	solve;
		std::vector<std::vector<int>>	vec({{1}});
		std::cout << solve.equalPairs(vec) << std::endl;
	}
	return (0);
}