#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

int N;
vi edges[101];
int dfsnum[101], dfslow[101], dfspar[101], dfscounter, rootch;
char vis[101];

void dfs(int u)
{
	dfsnum[u] = dfslow[u] = dfscounter;
	dfscounter += 1;

	for (int i = 0; i < edges[u].size(); i++)
	{
		int v = edges[u][i];
		if (!vis[v])
		{
			dfspar[v] = u;
			if (u == 0)
				rootch += 1;
			dfs(v);

			if (dfslow[v] >= dfsnum[u])
				cout << u << endl;
			dfslow[u] = min(dfslow[u], dfslow[v]);
		}
		else if (v != dfspar[u])
			dfslow[u] = min(dfslow[u], dfsnum[v]);
	}
}

int main()
{
	while (scanf("%d\n", &N) != EOF)
	{
		if (N == 0)
			break;
		for (int n = 0; n <= N; n++)
			edges[n].clear(), dfsnum[n] = 0, dfslow[n] = 0, dfspar[n] = 0, vis[n] = false;
		dfscounter = 0, rootch = 0;

		string in; 
		while (getline(cin, in))
		{
			if (in == "0") 
				break;
			int a = in[0] - '0';
			for (int i = 2; i < in.size(); i+=2)
			{
				int b = in[i] - '0';
				edges[a].push_back(b), edges[b].push_back(a);
			}
		}

		dfs(0);
	}
}
