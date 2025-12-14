#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
	private:
		int	numSpells;
	public:
		std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success);
};

std::vector<int> Solution::successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success)
{
	std::vector<int>::iterator	find;
	std::vector<int>			goodPotions(spells.size());
	long long					minPower;

	numSpells = spells.size();
	std::sort(potions.begin(), potions.end());

	for (int spell = 0; spell < numSpells; spell++)
	{
		minPower = success / spells[spell] + ((success % spells[spell]) > 0);
		find = std::lower_bound(potions.begin(), potions.end(), minPower);
		goodPotions[spell] = std::distance(find, potions.end());
	}
	return goodPotions;
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

	std::vector<int>	spells1({5,1,3});
	std::vector<int>	potions1({1,2,3,4,5});
	std::vector<int>	spells2({3,1,2});
	std::vector<int>	potions2({8,5,8});
	std::vector<int>	spells3({5});
	std::vector<int>	potions3({8,7,6,5,4,2,1});
	std::vector<int>	spells4({1});
	std::vector<int>	potions4({5,5,5,5,5});
	std::vector<int>	result;

	result = solve.successfulPairs(spells1, potions1, 7);
	PrintVector(result);
	result = solve.successfulPairs(spells2, potions2, 16);
	PrintVector(result);
	result = solve.successfulPairs(spells3, potions3, 11);
	PrintVector(result);
	result = solve.successfulPairs(spells4, potions4, 6);
	PrintVector(result);
	return (0);
}