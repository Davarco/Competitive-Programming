#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int T, N;
vi edges[50001];
int visited[50001];

int dfs(int n)
{
	if (visited[n] == -1) return 0;
	if (visited[n] != 0) return visited[n];
	visited[n] = -1;
	visited[n] = 1+dfs(edges[n][0]);
	return visited[n];
}

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int n = 0; n <= N; n++) edges[n].clear();
		for (int n = 0; n < N; n++)
		{
			int a, b; cin >> a >> b;
			edges[a].push_back(b);
		}
		for (int n = 0; n <= N; n++) visited[n] = 0;

		int best = 0;
		int best_idx = 0;
		for (int n = 1; n <= N; n++)
			if (!visited[n])
			{
				int next = dfs(n);
				if (next > best)
					best = next, best_idx = n;
			}
		printf("Case %d: %d\n", t+1, best_idx);
	}
}
