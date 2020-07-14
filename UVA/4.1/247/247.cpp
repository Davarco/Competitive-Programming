#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;

int N, M, T;
vector<string> names;
int used[25][25];
vi edges[25];
vi dfs_num, dfs_min, dfs_now, dfs_vis; int dfs_counter;

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
			if (u != v)
				printf("%s, ", names[v].c_str());
			else
			{
				printf("%s\n", names[v].c_str());
				break;
			}
		}
	}
}

int main()
{
	T = 0;
	while (cin >> N >> M)
	{
		if (N == 0 && M == 0) break;
		for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) used[r][c] = false;
		for (int n = 0; n < N; n++) edges[n].clear();
		unordered_map<string, int> um; int idx = 0; names.assign(N, "");
		dfs_num.assign(N, -1), dfs_min.assign(N, 0), dfs_vis.assign(N, 0), dfs_counter = 0;
		for (int m = 0; m < M; m++)
		{
			string a, b; cin >> a >> b;
			if (um.find(a) == um.end()) names[idx] = a, um[a] = idx++;
			if (um.find(b) == um.end()) names[idx] = b, um[b] = idx++;
			if (!used[um[a]][um[b]]) edges[um[a]].push_back(um[b]), used[um[a]][um[b]] = true;
		}
		if (T != 0) printf("\n");
		printf("Calling circles for data set %d:\n", ++T);
		for (int i = 0; i < N; i++) if (dfs_num[i] == -1) dfs(i);
	}
}
