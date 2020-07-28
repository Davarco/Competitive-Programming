#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 100000000

int C, N, E, T, M;
vii edges[100];

int main()
{
	cin >> C;
	for (int c = 0; c < C; c++)
	{
		cin >> N >> E >> T >> M, E -= 1;
		for (int n = 0; n < N; n++)
			edges[n].clear();
		for (int m = 0; m < M; m++)
		{
			int a, b, c;
			cin >> a >> b >> c, a -= 1, b -= 1;
			edges[b].push_back(ii(a, c));
		}

		vi dist(N, INF);
		priority_queue<ii, vii, greater<ii>> pq;
		dist[E] = 0, pq.push(ii(0, E));
		while (pq.size() > 0)
		{
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if (d > dist[u])
				continue;
			for (int i = 0; i < edges[u].size(); i++)
			{
				ii v = edges[u][i];
				if (dist[u] + v.second < dist[v.first])
				{
					dist[v.first] = dist[u] + v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}

		int count = 0;
		for (int n = 0; n < N; n++)
			if (dist[n] <= T)
				count += 1;
		cout << count << endl;
		if (c != C-1)
			cout << endl;
	}
}
