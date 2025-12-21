#include <stdio.h>
#include <stdbool.h>

int	CheckPeak(int* nums, int index, int numsSize)
{
	bool	isGreaterThanLeft = false;
	bool	isGreaterThanRight = false;

	if ((index == 0) || (nums[index - 1] < nums[index]))
		isGreaterThanLeft = true;
	if ((index == (numsSize - 1)) || nums[index + 1] < nums[index])
		isGreaterThanRight = true;
	if (isGreaterThanLeft && isGreaterThanRight)
		return 0;
	if (!isGreaterThanLeft && isGreaterThanRight)
		return -1;
	return 1;
}

int findPeakElement(int* nums, int numsSize)
{
	int	left = 0;
	int	right = numsSize - 1;
	int	middle;
	int	nextMoveDirection;

	if (CheckPeak(nums, left, numsSize) == 0)
		return left;
	if (CheckPeak(nums, right, numsSize) == 0)
		return right;
	while ((right - left) > 1)
	{
		middle = ((right - left) / 2) + left;
		nextMoveDirection = CheckPeak(nums, middle, numsSize);
		if (nextMoveDirection == 0)
			return middle;
		if (nextMoveDirection < 0)
			right = middle;
		else
			left = middle;
	}
	return middle;
}

int	main()
{
	int	nums1[4] = {1,2,3,1};
	int	nums2[3] = {1,2,3};
	int	result;

	result = findPeakElement(nums1, 4);
	printf("%d\n", result);
	result = findPeakElement(nums2, 3);
	printf("%d\n", result);
	return (0);
}