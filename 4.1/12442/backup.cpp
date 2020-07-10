#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int T, N;
vi edges[50001];
int visited[50001];
vi current;

int dfs(int n)
{
	if (visited[n] == -1) return 0;
	if (visited[n] != 0) return visited[n];
	current.push_back(n);
	visited[n] = -1;
	int best = 1;
	for (int i = 0; i < edges[n].size(); i++)
		if (visited[edges[n][i]] != -1)
			best = max(best, 1+dfs(edges[n][i]));
	return best;
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
				current.clear();
				int next = dfs(n);
				for (int i = 0; i < current.size(); i++) visited[current[i]] = next;
				if (next > best) best = next, best_idx = n;
			}
		printf("Case %d: %d\n", t+1, best_idx);
	}
}
