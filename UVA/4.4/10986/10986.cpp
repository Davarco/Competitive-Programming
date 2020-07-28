#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 100000000

int C, N, M, S, T;
vii edges[20000];

int main()
{
	cin >> C;
	for (int c = 0; c < C; c++)
	{
		cin >> N >> M >> S >> T;
		for (int n = 0; n < N; n++)
			edges[n].clear();
		for (int m = 0; m < M; m++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edges[a].push_back(ii(b, c));
			edges[b].push_back(ii(a, c));
		}

		vi dist(N, INF);
		priority_queue<ii, vii, greater<ii>> pq;
		dist[S] = 0, pq.push(ii(0, S));
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
		printf("Case #%d: ", c+1);
		if (dist[T] == INF)
			printf("unreachable\n");
		else
			printf("%d\n", dist[T]);
	}
}
