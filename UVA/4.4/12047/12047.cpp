#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000000

int C, N, M, S, T, P;

int main()
{
	cin >> C;
	for (int c = 0; c < C; c++)
	{
		cin >> N >> M >> S >> T >> P, S -= 1, T -= 1;

		vii G0[N], G1[N];	
		for (int m = 0; m < M; m++)
		{
			int u, v, w;
			cin >> u >> v >> w, u -= 1, v -= 1;
			G0[u].push_back(ii(v, w)), G1[v].push_back(ii(u, w));
		}

		vi dist0(N, INF);
		priority_queue<ii, vii, greater<ii>> pq0;
		dist0[S] = 0, pq0.push(ii(0, S));
		while (pq0.size() > 0)
		{
			ii front = pq0.top(); pq0.pop();
			int d = front.first, u = front.second;
			if (d > dist0[u])
				continue;
			for (int i = 0; i < G0[u].size(); i++)
			{
				ii e = G0[u][i];
				if (dist0[u] + e.second < dist0[e.first])
				{
					dist0[e.first] = dist0[u] + e.second;
					pq0.push(ii(dist0[e.first], e.first));
				}
			}
		}

		vi dist1(N, INF);
		priority_queue<ii, vii, greater<ii>> pq1;
		dist1[T] = 0, pq1.push(ii(0, T));
		while (pq1.size() > 0)
		{
			ii front = pq1.top(); pq1.pop();
			int d = front.first, u = front.second;
			if (d > dist1[u])
				continue;
			for (int i = 0; i < G1[u].size(); i++)
			{
				ii e = G1[u][i];
				if (dist1[u] + e.second < dist1[e.first])
				{
					dist1[e.first] = dist1[u] + e.second;
					pq1.push(ii(dist1[e.first], e.first));
				}
			}
		}

		int best = -1;
		for (int n = 0; n < N; n++)
		{
			for (int i = 0; i < G0[n].size(); i++)
			{
				ii e = G0[n][i];
				int dist = dist0[n] + dist1[e.first] + e.second;
				if (dist < P && e.second > best)
					best = e.second;
			}
		}
		cout << best << endl;
	}
}
