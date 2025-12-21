#include <stdbool.h>
#include <stdio.h>

bool	isVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'u' || c == 'i' || c == 'o')
		return true;
	if (c == 'A' || c == 'E' || c == 'U' || c == 'I' || c == 'O')
		return true;
	return false;
}

void	swapChars(char* a, char* b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char* reverseVowels(char* s)
{
	int	right = 0;
	int	left = 0;

	while (s[right] != '\0')
		right++;
	right--;
	while (left < right)
	{
		while (left < right && isVowel(s[left]) == false)
			left++;
		while (right > left && isVowel(s[right]) == false)
			right--;
		swapChars(&s[left], &s[right]);
		left++;
		right--;
	}
	return s;
}

int	main()
{
	char	test1[30] = "leetcode";
	char	test2[30] = "IceCreAm";
	char	test3[30] = "a";
	char	test4[30] = "Isau";
	
	printf("%s\n", reverseVowels(test1));
	printf("%s\n", reverseVowels(test2));
	printf("%s\n", reverseVowels(test3));
	printf("%s\n", reverseVowels(test4));
	return (0);
}