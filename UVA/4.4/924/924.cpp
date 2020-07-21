#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

int E, T;
vi edges[2500];

int main()
{
	cin >> E;
	for (int e = 0; e < E; e++)
	{
		int N; 
		cin >> N;
		for (int n = 0; n < N; n++)
		{
			int f;
			cin >> f;
			edges[e].push_back(f);
		}
	}
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int s;
		cin >> s;

		vi distance(E, -1);
		queue<int> q;
		distance[s] = 0, q.push(s);
		while (q.size() > 0)
		{
			int u = q.front(); q.pop();
			for (int i = 0; i < edges[u].size(); i++)
			{
				int v = edges[u][i];
				if (distance[v] == -1)
				{
					distance[v] = distance[u] + 1;
					q.push(v);
				}
			}
		}
		
		vi counts(E);
		for (int e = 0; e < E; e++)
			if (distance[e] != -1)
				counts[distance[e]] += 1;
		
		counts[0] = 0;
		int best = 0;
		for (int e = 1; e < E; e++)
			if (counts[e] > counts[best])
				best = e;

		if (best == 0)
			cout << 0 << endl;
		else
			cout << counts[best] << " " << best << endl;
	}
}
