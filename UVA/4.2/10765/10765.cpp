#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int N, M;
vi edges[10001];
vi dfs_num, dfs_low, dfs_parent, counts; int dfs_counter, rootch;
vector<ii> top;

void dfs(int u)
{
	dfs_num[u] = dfs_low[u] = dfs_counter++;	
	for (int i = 0; i < edges[u].size(); i++)
	{
		int v = edges[u][i];
		if (dfs_num[v] == -1)
		{
			if (u == 0)
				rootch += 1;
			dfs_parent[v] = u;
			dfs(v);
			if (dfs_low[v] >= dfs_num[u])
				counts[u] += 1;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

bool cmp(ii a, ii b)
{
	if (a.second != b.second) 
		return a.second > b.second;
	else
		return a.first < b.first;
}

int main()
{
	while (cin >> N >> M)
	{
		if (N == 0 && M == 0)
			break;
		int a, b;
		for (int n = 0; n < N; n++) 
			edges[n].clear();
		while (cin >> a >> b) 
			if (a == -1 && b == -1)
				break;
			else
				edges[a].push_back(b), edges[b].push_back(a);
		
		dfs_num.assign(N, -1), dfs_low.assign(N, 0), dfs_parent.assign(N, 0), counts.assign(N, 1);
		dfs_counter = 0, rootch = 0;
		dfs(0);

		counts[0] = rootch;	
		top.clear();
		for (int n = 0; n < N; n++)
			top.push_back(make_pair(n, counts[n]));
		sort(top.begin(), top.end(), cmp);
		for (int n = 0; n < M; n++)
			printf("%d %d\n", top[n].first, top[n].second); cout << endl;
	}
}
