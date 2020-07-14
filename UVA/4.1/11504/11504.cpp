#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;

int T, N, M;
vi edges[100000], reversed[100000];
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
		bool flag = true;
		unordered_set<int> us;
		while (true)
		{
			int v = dfs_now.back(); dfs_now.pop_back();
			dfs_vis[v] = false;
			us.insert(v);
			if (u == v) 
				break;
		}
		for (auto it = us.begin(); it != us.end(); it++)
		{
			int e = *it;
			for (int i = 0; i < reversed[e].size(); i++)
				if (us.count(reversed[e][i]) == 0)
					flag = false;
			if (!flag) break;
		}
		if (flag) scc += 1;
	}
}

int main()
{
	cin >> T;
	while (cin >> N >> M)
	{
		for (int n = 0; n < N; n++)
			edges[n].clear(), reversed[n].clear();
		for (int m = 0; m < M; m++)
		{
			int a, b; cin >> a >> b; a -= 1; b -= 1;
			edges[a].push_back(b);
			reversed[b].push_back(a);
		}
		dfs_num.assign(N, -1), dfs_min.assign(N, 0), dfs_vis.assign(N, 0), dfs_counter = 0, scc = 0;

		for (int n = 0; n < N; n++)
			if (dfs_num[n] == -1)
				dfs(n);
		cout << scc << endl;
	}
}
