#include <iostream>
#include <queue>
#include <algorithm>

//it is actually quite slow, at around 65%, not sure why,
//maybe lose time with memory allocation

class Solution
{
	private:
		std::priority_queue<int, std::vector<int>, std::greater<int>>	highestNums;
		int	size;
		static bool comparePair(std::pair<int, int>& a, std::pair<int, int>& b);
	public:
		long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k);
};

bool Solution::comparePair(std::pair<int, int>& a, std::pair<int, int>& b)
{
	return a.second > b.second;
}


long long	Solution::maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k)
{
	std::vector<std::pair<int, int>>	pairs;
	long long							bestSum;
	long long							currentSum = 0;

	size = nums1.size();

	pairs.reserve(size);
	for (int i = 0; i < size; i++)
		pairs.push_back(std::pair<int, int>(nums1[i], nums2[i]));
	std::sort(pairs.begin(), pairs.end(), comparePair);
	for (int i = 0; i < k; i++)
	{
		highestNums.push(pairs[i].first);
		currentSum += pairs[i].first;
	}
	bestSum = currentSum * pairs[k - 1].second;
	for (int i = k; i < size; i++)
	{
		highestNums.push(pairs[i].first);
		currentSum += pairs[i].first - highestNums.top();
		highestNums.pop();
		bestSum = std::max(bestSum, currentSum * pairs[i].second);
	}
	return bestSum;
}

int main()
{
	{
		Solution	solve;
		std::vector<int>	nums1({1,3,3,2});
		std::vector<int>	nums2({2,1,3,4});

		std::cout << solve.maxScore(nums1, nums2, 3) << std::endl;
	}
	{
		Solution	solve;
		std::vector<int>	nums1({4,2,3,1,1});
		std::vector<int>	nums2({7,5,10,9,6});

		std::cout << solve.maxScore(nums1, nums2, 1) << std::endl;
	}
	{
		Solution	solve;
		std::vector<int>	nums1({0, 5, 6});
		std::vector<int>	nums2({7, 8, 6});

		std::cout << solve.maxScore(nums1, nums2, 2) << std::endl;
	}

	return 0;
}