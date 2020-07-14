#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
string grid[100];
char vis[100][100];

int dfs(int r, int c)
{
	if (r < 0 || r == N || c < 0 || c == N || grid[r][c] == '.' || vis[r][c])
		return 0;
	vis[r][c] = true;
	int ship = grid[r][c] == 'x' ? 1 : 0;
	return ship + dfs(r+1, c) + dfs(r-1, c) + dfs(r, c+1) + dfs(r, c-1);
}

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int n = 0; n < N; n++) cin >> grid[n];
		for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) vis[r][c] = false;

		int count = 0;
		for (int r = 0; r < N; r++) for (int c = 0; c < N; c++)
			if (dfs(r, c))
				count += 1;
		printf("Case %d: %d\n", t+1, count);
	}
}
