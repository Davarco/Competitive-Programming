#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

int V, A, B;
vi edges[301];

int main()
{
	while (cin >> V)
	{
		if (V == 0) break;
		for (int v = 1; v <= V; v++) edges[v].clear();
		while (cin >> A >> B) 
		{
			if (A == 0 && B == 0) break;
			edges[A].push_back(B);
			edges[B].push_back(A);
		}

		vi C(V+1, -1);
		bool bipartite = true;	
		for (int n = 1; n <= V; n++)
		{
			if (C[n] == -1)
			{
				queue<int> q; q.push(n); C[n] = 0;
				while (q.size() > 0)
				{
					int u = q.front(); q.pop();
					for (int i = 0; i < edges[u].size(); i++)
					{
						int v = edges[u][i];
						if (C[v] == -1)
							C[v] = 1-C[u], q.push(v);
						else if (C[v] == C[u]) 
						{
							bipartite = false;
							break;
						}
					}
				}
			}
		}

		if (bipartite) 
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
