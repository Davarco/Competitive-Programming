#include <iostream>

void f(int grid[3][3])
{
	int next[3][3];
	next[0][0] = (grid[1][0]+grid[0][1]) % 2;
	next[0][1] = (grid[0][0]+grid[0][2]+grid[1][1]) % 2;
	next[0][2] = (grid[0][1]+grid[1][2]) % 2;
	next[1][0] = (grid[0][0]+grid[2][0]+grid[1][1]) % 2;
	next[1][1] = (grid[1][0]+grid[0][1]+grid[1][2]+grid[2][1]) % 2;
	next[1][2] = (grid[1][1]+grid[0][2]+grid[2][2]) % 2;
	next[2][0] = (grid[1][0]+grid[2][1]) % 2;
	next[2][1] = (grid[2][0]+grid[2][2]+grid[1][1]) % 2;
	next[2][2] = (grid[2][1]+grid[1][2]) % 2;
	for (int r = 0; r < 3; r++)
		for (int c = 0; c < 3; c++)
			grid[r][c] = next[r][c];
}

bool zero(int grid[3][3])
{
	for (int r = 0; r < 3; r++)
		for (int c = 0; c < 3; c++)
			if (grid[r][c] == 1)
				return false;
	return true;
}

int main()
{
	int N;
	scanf("%d\n", &N);

	for (int i = 0; i < N; i++)
	{
		int grid[3][3];
		for (int r = 0; r < 3; r++)
			scanf("%1i%1i%1i\n", &grid[r][0], &grid[r][1], &grid[r][2]);

		int index = -1;
		while (!zero(grid))
		{
			f(grid);
			index += 1;
		}
		printf("%d\n", index);
	}
}
