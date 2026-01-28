#include <iostream>
#include <vector>



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

	std::vector<int>	vec({100, -90, 20, -20, 1, 2, 3, -110});
	std::vector<int>	result;

	result = solve.asteroidCollision(vec);
	PrintVector(result);
	return (0);
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

int	main()
{
	char	test[30] = "abbbbbbbbbbbb";
	
	printf("Length: %d, string: %s\n", compress(test, 13), test);
	return (0);
}