#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M, N, X, Y; 
char L;
string table[20];
char visited[20][20];

int dfs(int r, int c)
{
	if (c < 0) 
		c = N-1;
	if (c == N)
		c = 0;
	if (r < 0 || r == M || table[r][c] != L || visited[r][c])
		return 0;
	visited[r][c] = true;
	return 1 + dfs(r+1, c) + dfs(r-1, c) + dfs(r, c+1) + dfs(r, c-1);
}

int main()
{
	while (cin >> M >> N)
	{
		for (int m = 0; m < M; m++) cin >> table[m];
		cin >> X >> Y;
		L = table[X][Y];
		for (int r = 0; r < M; r++) for (int c = 0; c < N; c++) visited[r][c] = false;

		dfs(X, Y);
		int best = 0;
		for (int r = 0; r < M; r++) for (int c = 0; c < N; c++)
			if (!visited[r][c])
			{
				int next = dfs(r, c);
				if (next > best)
					best = next;
			}
		cout << best << endl;
	}
}
