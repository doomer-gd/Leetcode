#include <vector>
#include <iostream>

struct Buttons
{
	std::string	buttons[8] = {"abc", "def", "ghi", "jkl", "nmo", "pqrs", "tuv", "wxyz"};
	int			lenghts[8] = {3,3,3,3,3,4,3,4};
};

class Solution {
	private:
		int							lengthTotal;
		int							maxDepth;
		int							indexResult = 0;
		std::vector<int>			digitsNum;
		std::string					currentLine;
		std::vector<std::string>	output;
		Buttons						phone;

		void	BacktrackString(int depth);
	public:
		std::vector<std::string> letterCombinations(std::string digits);
};

std::vector<std::string> Solution::letterCombinations(std::string digits)
{
	int numOutput = 1;

	lengthTotal = digits.size();
	maxDepth = lengthTotal - 1;
	digitsNum = std::vector<int>(lengthTotal);
	currentLine = std::string(lengthTotal, ' ');
	for (int i = 0; i < lengthTotal; i++)
	{
		digitsNum[i] = digits[i] - '2';
		numOutput *= phone.lenghts[digitsNum[i]];
	}
	output = std::vector<std::string>(numOutput);
	BacktrackString(0);
	return output;
}

void	Solution::BacktrackString(int depth)
{
	int	currentSize = phone.lenghts[digitsNum[depth]];

	for (int i = 0; i < currentSize; i++)
	{
		currentLine[depth] = phone.buttons[digitsNum[depth]][i];
		if (depth < maxDepth)
			BacktrackString(depth + 1);
		else
		{
			output[indexResult] = currentLine;
			indexResult++;
		}
	}
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
	Solution	solve1;
	Solution	solve2;

	std::vector<std::string>	result;

	std::string					test2("2");
	result = solve1.letterCombinations(test2);
	PrintVector(result);
	
	std::string					test1("7");
	result = solve2.letterCombinations(test1);
	PrintVector(result);

	return (0);
}