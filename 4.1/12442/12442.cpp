#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int T, N;
vi edges[50001];
char visited[50001];
int dp[50001];

int dfs(int n)
{
	visited[n] = true;
	int martians = 0;
	if (edges[n].size() != 0 && !visited[edges[n][0]])
		martians = 1 + dfs(edges[n][0]);
	visited[n] = false;
	dp[n] = martians;
	return dp[n];
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
		for (int n = 0; n <= N; n++) visited[n] = false;
		for (int n = 0; n <= N; n++) dp[n] = -1;

		int best = 0;
		int best_idx = 0;
		for (int n = 1; n <= N; n++)
		{
			if (dp[n] == -1)
				dfs(n);
			if (dp[n] > best)
				best = dp[n], best_idx = n;
		}
		printf("Case %d: %d\n", t+1, best_idx);
	}
}
