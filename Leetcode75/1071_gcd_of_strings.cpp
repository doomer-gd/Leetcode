#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <string.h>

class Solution {
	private:
		int	gcd(int a, int b)
		{
			while (a != 0 && b != 0)
			{
				a = b % a;
				b = a % b;
			}
			return a + b;
		}
		bool	CheckIsDivisible(std::string str, int quotient, char* divider, int lengthDiv)
		{
			char*	ptr = str.begin().base() + lengthDiv;

			for (int i = 1; i < quotient; i++)
			{
				if (strncmp(ptr, divider, lengthDiv) != 0)
					return false;
				ptr += lengthDiv;
			}
			return true;
		}
	public:
		std::string gcdOfStrings(std::string str1, std::string str2)
		{
			int		length1 = str1.size();
			int		length2 = str2.size();
			int		lengthSubstr = gcd(length1, length2);
			char	divider[std::max(length1, length2) + 1];

			std::cout << lengthSubstr << " sizes " << length1 << " " << length2 <<  std::endl;
			while (lengthSubstr > 0)
			{
				if (((length1 % lengthSubstr) == 0) && ((length2 % lengthSubstr) == 0))
				{
					bool	isDivisible;

					strncpy(divider, str1.c_str(), lengthSubstr);
					divider[lengthSubstr] = '\0';
					isDivisible = CheckIsDivisible(str1, length1 / lengthSubstr, divider, lengthSubstr);
					if (isDivisible)
						isDivisible = CheckIsDivisible(str2, length2 / lengthSubstr, divider, lengthSubstr);
					if (isDivisible)
						return std::string(divider);
				}
				lengthSubstr--;
			}
			return std::string();
		}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	std::string	str1 = std::string("TAUXXTAUXXTAUXXTAUXXTAUXX");
	std::string	str2 = std::string("TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX");
	std::cout << solve.gcdOfStrings(str1, str2) << std::endl;
	return (0);
}