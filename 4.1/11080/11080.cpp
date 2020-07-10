#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

int T, V, E;
vi edges[200];

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> V >> E;
		for (int v = 0; v < V; v++)
			edges[v].clear();
		for (int e = 0; e < E; e++)
		{
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		vi C(V, -1);
		queue<int> q;
		char bipartite = true;
		int combined = 0;
		for (int n = 0; n < V; n++)
		{
			if (C[n] == -1)
			{
				int count[2] = { 1, 0 };
				q.push(n); C[n] = 0;
				while (q.size() != 0)
				{
					int u = q.front(); q.pop();
					for (int i = 0; i < edges[u].size(); i++)
					{
						int v = edges[u][i];
						if (C[v] == -1)
							C[v] = 1-C[u], q.push(v), count[C[v]] += 1;
						else if (C[v] == C[u])
						{
							bipartite = false;
							break;
						}
					}
				}
				combined += max(1, min(count[0], count[1]));
			}
		}
		if (bipartite)
			cout << combined << endl;
		else 
			cout << -1 << endl;
	}
}
