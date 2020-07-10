#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

int N, L;
vi edges[200];

int main()
{
	while (cin >> N)
	{
		if (N == 0) break;
		for (int n = 0; n < N; n++)
			edges[n].clear();
		cin >> L;
		for (int i = 0; i < L; i++) 
		{
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
		}

		vi colors(N, -1);	
		bool bipartite = true;
		queue<int> q; 
		q.push(0); colors[0] = 0;
		while (q.size() != 0)
		{
			int u = q.front(); q.pop();
			for (int i = 0; i < edges[u].size(); i++)
			{
				int v = edges[u][i];
				if (colors[v] == -1)
					colors[v] = 1-colors[u], q.push(v);
				else if (colors[v] == colors[u])
				{
					bipartite = false;
					break;
				}
			}
		}
		if (bipartite)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
	}
}
