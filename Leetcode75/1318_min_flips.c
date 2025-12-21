#include <stdio.h>

int minFlips(int a, int b, int c)
{
	int	originalAnd;
	int	compareXor;
	int	result = 0;

	originalAnd = a & b;
	compareXor = c ^ (a | b);
	while (compareXor || originalAnd)
	{
		if ((compareXor % 2) == 1)
			result += originalAnd % 2 + 1;
		compareXor >>= 1;
		originalAnd >>= 1;
	}
	return result;
}

int	main()
{
	int	nums1[3] = {2,6,5};
	int	nums2[3] = {2,4,7};
	int	nums3[3] = {1,2,3};
	int	nums4[3] = {1,1,0};
	int	result;

	result = minFlips(nums1[0], nums1[1], nums1[2]);
	printf("%d\n", result);
	result = minFlips(nums2[0], nums2[1], nums2[2]);
	printf("%d\n", result);
	result = minFlips(nums3[0], nums3[1], nums3[2]);
	printf("%d\n", result);
	result = minFlips(nums4[0], nums4[1], nums4[2]);
	printf("%d\n", result);
	return (0);
}