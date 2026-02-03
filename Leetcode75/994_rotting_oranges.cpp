#include <iostream>
#include <vector>
#include <queue>

struct Coords
{
	int	x;
	int	y;

	Coords(int x, int y): x(x), y(y){};
	Coords(): x(0), y(0){};
};

class Solution
{
	private:
		std::queue<Coords>	queueVisits;
		std::vector<std::vector<bool>>	visitedTiles;
		int					sizeX;
		int					sizeY;
		int					round = 0;
		int					visitsCurrent = 0;
		int					visitsNext = 0;
		void	FindFirstRotten(std::vector<std::vector<int>>& grid);
		void	InfectNeighbours(std::vector<std::vector<int>>& grid, Coords tile);
		void	AddToQueue(Coords tile);
		int		VerifyAllRotten(std::vector<std::vector<int>>& grid);
	public:
		int orangesRotting(std::vector<std::vector<int>>& grid);
};

int	Solution::orangesRotting(std::vector<std::vector<int>>& grid)
{
	Coords	nextTile;
	
	sizeY = grid.size();
	sizeX = grid[0].size();
	visitedTiles = std::vector<std::vector<bool>>(sizeY, std::vector<bool>(sizeX, false));
	FindFirstRotten(grid);
	while (visitsCurrent > 0)
	{
		for (;visitsCurrent > 0; visitsCurrent--)
		{
			nextTile = queueVisits.front();
			InfectNeighbours(grid, nextTile);
			queueVisits.pop();
		}
		visitsCurrent = visitsNext;
		visitsNext = 0;
		round++;
	}
	return VerifyAllRotten(grid);
}

void	Solution::FindFirstRotten(std::vector<std::vector<int>>& grid)
{
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			if (grid[y][x] == 2)
				AddToQueue(Coords(x,y));
		}
	}
	visitsCurrent = visitsNext;
	visitsNext = 0;
}

void	Solution::InfectNeighbours(std::vector<std::vector<int>>& grid, Coords tile)
{
	int	x = tile.x;
	int	y = tile.y;

	if (x > 0 && grid[y][x - 1] == 1)
		AddToQueue(Coords(x - 1, y));
	if ((x < sizeX - 1) && grid[y][x + 1] == 1)
		AddToQueue(Coords(x + 1, y));
	if (y > 0 && grid[y - 1][x] == 1)
		AddToQueue(Coords(x, y - 1));
	if (y < (sizeY - 1) && grid[y + 1][x] == 1)
		AddToQueue(Coords(x, y + 1));
}

void	Solution::AddToQueue(Coords tile)
{
	if (visitedTiles[tile.y][tile.x] == false)
	{
		queueVisits.push(tile);
		visitedTiles[tile.y][tile.x] = true;
		visitsNext++;
	}
}

int	Solution::VerifyAllRotten(std::vector<std::vector<int>>& grid)
{
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			if (grid[y][x] == 1 && visitedTiles[y][x] == false)
				return -1;
		}
	}
	return std::max(round - 1, 0);
}

int main()
{
	{
		Solution solve;
		std::vector<std::vector<int>>	grid({	{0,2,0},
												{1,1,0},
												{1,1,1}});
		std::cout << solve.orangesRotting(grid) << std::endl;
	}
	{
		Solution solve;
		std::vector<std::vector<int>>	grid({	{2,1,1},
												{1,1,0},
												{0,1,1}});
		std::cout << solve.orangesRotting(grid) << std::endl;
	}
	{
		Solution solve;
		std::vector<std::vector<int>>	grid({	{2,1,1},
												{0,1,1},
												{1,0,1}});
		std::cout << solve.orangesRotting(grid) << std::endl;
	}
	{
		Solution solve;
		std::vector<std::vector<int>>	grid({{0}});
		std::cout << solve.orangesRotting(grid) << std::endl;
	}
	return 0;
}