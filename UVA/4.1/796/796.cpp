#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <tuple>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int N;
vi edges[10000];
vi dfs_num, dfs_low, dfs_parent; int dfs_counter;
vector<ii> criticals;

void dfs(int u)
{
	dfs_num[u] = dfs_counter, dfs_low[u] = dfs_counter, dfs_counter += 1;
	for (int i = 0; i < edges[u].size(); i++)
	{
		int v = edges[u][i];
		if (dfs_num[v] == -1)
		{
			dfs_parent[v] = u;
			dfs(v);
			if (dfs_low[v] > dfs_num[u])
				criticals.push_back(make_pair(min(u, v), max(u, v)));
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main()
{
	while (cin >> N)
	{
		for (int n = 0; n < N; n++)
			edges[n].clear();
		for (int n = 0; n < N; n++)
		{
			int a, b, c; string in;
			cin >> a >> in;
			sscanf(in.c_str(), "(%d)", &b);
			for (int i = 0; i < b; i++)
			{
				cin >> c; 
				edges[a].push_back(c); edges[c].push_back(a);
			}
		}

		dfs_num.assign(N, -1), dfs_low.assign(N, 0), dfs_parent.assign(N, 0), dfs_counter = 0;
		criticals.clear();

		for (int n = 0; n < N; n++)
			if (dfs_num[n] == -1)
				dfs(n);
		sort(criticals.begin(), criticals.end());
		printf("%d critical links\n", criticals.size());
		for (int i = 0; i < criticals.size(); i++)
			printf("%d - %d\n", criticals[i].first, criticals[i].second);
		cout << endl;
	}
}
