#include <stdio.h>

#define MAX_TILES 1000000007l

int numTilings(int n)
{
	static int		tilings[1001];
	static int		known = 3;
	long			newTile;

	tilings[1] = 1;
	tilings[2] = 2;
	tilings[3] = 5;
	if (n <= known)
		return tilings[n];
	for (int i = known; i < n; i++)
	{
		newTile = 2l * (long)tilings[i] + tilings[i - 2];
		tilings[i + 1] = newTile % MAX_TILES;
	}
	known = n;
	return tilings[n];
}

int	main()
{
	int	result;

	result = numTilings(1);
	printf("%d\n", result);
	result = numTilings(2);
	printf("%d\n", result);
	result = numTilings(3);
	printf("%d\n", result);
	result = numTilings(4);
	printf("%d\n", result);
	result = numTilings(30);
	printf("%d\n", result);
	return (0);
}