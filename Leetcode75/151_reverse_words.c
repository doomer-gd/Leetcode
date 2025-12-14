#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ReverseInterval(char* str, int* borders)
{
	int		left = borders[0];
	int		right = borders[1];
	char	temp;

	while (left < right)
	{
		temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		left++;
		right--;
	}
}

bool	FindNextWord(char* str, int* borders)
{
	bool	isWord = false;
	while ((str[borders[0]] != '\0') && (str[borders[0]] == ' '))
		(borders[0])++;
	isWord = (str[borders[0]] != '\0');
	borders[1] = borders[0];
	while ((str[borders[1]] != '\0') && (str[borders[1]] != ' '))
		(borders[1])++;
	(borders[1])--;
	return isWord;
}

void	UnreverseRemoveSpaces(char* str)
{
	int	index = 0;
	int	shift = 1;
	int	borders[2];

	borders[0] = 0;
	while (FindNextWord(str, borders))
	{
		ReverseInterval(str, borders);
		shift += borders[0] - index - 1;
		for(index = borders[0]; index <= borders[1]; index++)
			str[index - shift] = str[index];
		if (str[index - shift] != '\0')
			str[index - shift] = ' ';
		borders[0] = borders[1];
		(borders[0])++;
	}
	str[index - shift] = '\0';
}

char*	reverseWords(char* s)
{
	int	borders[2];

	if (s == NULL)
		return NULL;
	borders[0] = 0;
	borders[1] = 0;
	while (s[borders[1]] != '\0')
		(borders[1])++;
	borders[1]--;
	ReverseInterval(s, borders);
	UnreverseRemoveSpaces(s);
	return s;
}

int	main()
{
	char	solve[25] = "the sky is blue";
	char*	line;

	line = malloc(16);
	line[15] = '\0';
	strncpy(line, solve, 15);
	reverseWords(line);
	printf("%s\n", solve);
	free(line);
	return (0);
}