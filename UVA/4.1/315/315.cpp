#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<int> vi;

int N;
vi edges[101];
int dfsnum[101], dfslow[101], dfspar[101], dfscounter, rootch;
char vertex[101];

void dfs(int u)
{
	dfsnum[u] = dfscounter, dfslow[u] = dfscounter, dfscounter += 1;
	for (int i = 0; i < edges[u].size(); i++)
	{
		int v = edges[u][i];
		if (dfsnum[v] == -1)
		{
			dfspar[v] = u;
			if (u == 1)
				rootch += 1;
			dfs(v);

			if (dfslow[v] >= dfsnum[u])
				vertex[u] = true;
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
			edges[n].clear(), dfsnum[n] = -1, dfslow[n] = 0, dfspar[n] = 0, vertex[n] = false;
		dfscounter = 0, rootch = 0;

		string in; stringstream ss;
		while (getline(cin, in))
		{
			if (in == "0") break;
			ss.clear(), ss.str(in);
			int a, b; ss >> a;
			while (ss >> b) edges[a].push_back(b), edges[b].push_back(a);
		}

		dfs(1);
		vertex[1] = rootch > 1;
		int count = 0;
		for (int n = 1; n <= N; n++) if (vertex[n]) count += 1;
		cout << count << endl;
	}
}
