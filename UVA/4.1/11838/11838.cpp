#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

int N, M;
vi edges[2000];
vi dfs_num, dfs_min, dfs_now, dfs_vis; int dfs_counter, scc;

void dfs(int u)
{
	dfs_num[u] = dfs_min[u] = dfs_counter++;
	dfs_now.push_back(u);
	dfs_vis[u] = true;
	for (int i = 0; i < edges[u].size(); i++)
	{
		int v = edges[u][i];
		if (dfs_num[v] == -1)
			dfs(v);
		if (dfs_vis[v])
			dfs_min[u] = min(dfs_min[u], dfs_min[v]);
	}
	if (dfs_num[u] == dfs_min[u])
	{
		while (true)
		{
			int v = dfs_now.back(); dfs_now.pop_back();
			dfs_vis[v] = false;
			if (u == v) 
				break;
		}
		scc += 1;
	}
}

int main()
{
	while (cin >> N >> M)
	{
		if (N == 0 && M == 0)
			break;
		for (int n = 0; n < N; n++)
			edges[n].clear();
		for (int m = 0; m < M; m++)
		{
			int v, w, p; cin >> v >> w >> p; v -= 1, w -= 1;
			if (p == 1)
				edges[v].push_back(w);
			else
				edges[v].push_back(w), edges[w].push_back(v);
		}
		dfs_num.assign(N, -1), dfs_min.assign(N, 0), dfs_vis.assign(N, 0), dfs_counter = 0, scc = 0;
		for (int n = 0; n < N; n++)
			if (dfs_num[n] == -1)
				dfs(n);
		if (scc > 1)
			cout << 0 << endl;
		else 
			cout << 1 << endl;
	}
}
