#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
	public:
		vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries)
		{
			int	sizeNums = nums.size();
			int	sizeQs = queries.size();
			vector<int>	qrs[2] = {nums, vector<int>(sizeNums)};
			vector<long long>	result(sizeQs, 0);
			vector<int>::iterator	median;

			for (int i = 0; i < sizeNums; i++)
			{
				qrs[1][i] = qrs[0][i] % k;
				qrs[0][i] = qrs[0][i] / k;
			}
			for (int j = 0; j < sizeQs; j++)
			{
				int start = queries[j][0];
				int end = queries[j][1];
				int	rem = qrs[1][start];
				int	middle = (end - start) / 2;
				int	median;

				for (int i = start + 1; i <= end; i++)
				{
					if (qrs[1][i] != rem)
					{
						result[j] = -1;
						break ;
					}
				}
				if (result[j] == -1)
					continue;
				vector<int>	sorter(qrs[0].begin() + start, qrs[0].begin() + end + 1);
				nth_element(sorter.begin(), sorter.begin() + middle, sorter.end());
				median = sorter[middle];
				for (size_t i = 0; i < sorter.size(); i++)
					result[j] += abs(median - sorter[i]);
			}
			return result;
		}
};


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

	std::vector<int>	nums({1,4,7});
	int					k = 3;
	std::vector<int>	vec2({2,4,6});
	std::vector<std::vector<int>> queries = {{0,1},{0,2}};
	std::vector<long long> result;

	result = solve.minOperations(nums, k, queries);
	PrintVector(result);
	std::cout << std::endl;
	return (0);
}