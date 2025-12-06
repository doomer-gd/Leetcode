#include <vector>
#include <iostream>


struct Coords
{
	int	x;
	int	y;
	Coords(int x, int y): x(x), y(y){};
};

class Solution {
	private:
		std::vector<std::vector<short>>	distances;
		int		width;
		int		height;
		int		depth = 0;
		int		bestResult = INT32_MAX;

		int		SideStep(std::vector<std::vector<char>>& maze, int x, int y);
		void	TryNeighbours(std::vector<std::vector<char>>& maze, int x, int y, int (&foundExit)[4]);
		void	RiseUp(std::vector<std::vector<char>>& maze, int x, int y, int& bestRoute);
		bool	IsExit(std::vector<std::vector<char>>& maze, int x, int y);
		bool	IsPassable(std::vector<std::vector<char>>& maze, int x, int y);
		void	ChooseBestRoute(int (&foundExit)[4], int& bestRoute);
	public:
		int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance)
		{
			width = maze[0].size();
			height = maze.size();
			distances = std::vector<std::vector<short>>(height, std::vector<short>(width, 0));
			maze[entrance[0]][entrance[1]] = '+';
			return SideStep(maze, entrance[1], entrance[0]);
		}
};

int	Solution::SideStep(std::vector<std::vector<char>>& maze, int x, int y)
{
	int	foundExit[4] = {-1, -1, -1, -1};
	int	bestRoute;

	depth++;
	if (distances[y][x] == 0)
		distances[y][x] = depth;
	if (depth > bestResult)
	{
		RiseUp(maze, x, y, bestRoute);
		return -1;
	}
	if (IsExit(maze, x, y))
	{
		RiseUp(maze, x, y, bestRoute);
		return (depth);
	}
	maze[y][x] = '+';
	TryNeighbours(maze, x, y, foundExit);
	ChooseBestRoute(foundExit, bestRoute);
	RiseUp(maze, x, y, bestRoute);
	return bestRoute;
}


void	Solution::RiseUp(std::vector<std::vector<char>>& maze, int x, int y, int& bestRoute)
{
	maze[y][x] = '.';
	depth--;
	if (bestRoute > 0 && bestRoute < bestResult)
		bestResult = bestRoute;
}

void	Solution::TryNeighbours(std::vector<std::vector<char>>& maze, int x, int y, int (&foundExit)[4])
{
	if (IsPassable(maze, x - 1, y))
		foundExit[0] = SideStep(maze, x - 1, y);
	if (IsPassable(maze, x, y - 1))
		foundExit[1] = SideStep(maze, x, y - 1);
	if (IsPassable(maze, x + 1, y))
		foundExit[2] = SideStep(maze, x + 1, y);
	if (IsPassable(maze, x, y + 1))
		foundExit[3] = SideStep(maze, x, y + 1);
}

void	Solution::ChooseBestRoute(int (&foundExit)[4], int& bestRoute)
{
	bestRoute = foundExit[0];
	for (int i = 1; i < 4; i++)
	{
		if (foundExit[i] > 0 && ((foundExit[i] < bestRoute) || bestRoute == -1))
			bestRoute = foundExit[i];
	}
}

bool Solution::IsExit(std::vector<std::vector<char>>& maze, int x, int y)
{
	if ((x == 0 || x == width - 1 || y == 0 || y == height - 1)
		&& maze[y][x] != '+')
		return true;
	return false;
}

bool Solution::IsPassable(std::vector<std::vector<char>>& maze, int x, int y)
{
	if ((x < 0) || (x > width - 1) || (y < 0) || (y > height - 1))
		return false;
	if (maze[y][x] == '.')
		return true;
	return false;
}

int	main()
{
	Solution	solve;


	std::vector<std::vector<char>> map1{{'+','+','.','+'}, {'.','.','.','+'}, {'+','+','+','.'}};
	std::vector<int>	entrance1 = {1, 2};
	std::vector<std::vector<char>> map2{{'+','+','+'}, {'.','.','.'}, {'+','+','+'}};
	std::vector<int>	entrance2 = {1, 0};

	std::vector<std::vector<char>> map3{{'+','.','+','+','+','+','+'},
										{'+','.','+','.','.','.','+'},
										{'+','.','+','.','+','.','+'},
										{'+','.','.','.','.','.','+'},
										{'+','+','+','+','.','+','.'}};
	std::vector<int>	entrance3 = {0, 1};

	// std::cout << solve.nearestExit(map1, entrance1) << std::endl;
	std::cout << solve.nearestExit(map2, entrance2) << std::endl;
	// std::cout << solve.nearestExit(map3, entrance3) << std::endl;
	return (0);
}

ТАБАЧНЫЕ КОРПОРАЦИИ ХОТЯТ ЗАВЛАДЕТЬ ТВОЕЙ ДУШОЙ!