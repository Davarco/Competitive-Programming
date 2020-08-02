#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

#define INF 100000000

int N, K, T[5];
vi F[5];

int main()
{
	while (scanf("%d %d\n", &N, &K) != EOF)
	{
		for (int n = 0; n < N; n++) F[n].clear();
		for (int n = 0; n < N-1; n++) scanf("%d ", &T[n]); scanf("%d\n", &T[N-1]);
		for (int n = 0; n < N; n++)
		{
			string in; getline(cin, in); stringstream ss(in);
			int f; while (ss >> f) F[n].push_back(f);
		}

		int dist[100][5];
		for (int a = 0; a < 100; a++) for (int b = 0; b < 5; b++) dist[a][b] = INF;
		priority_queue<iii, viii, greater<iii>> pq;
		for (int n = 0; n < N; n++)
			if (F[n].size() > 0 && F[n][0] == 0)
				dist[0][n] = 0, pq.push(iii(0, ii(0, n)));
		while (pq.size() > 0)
		{
			iii front = pq.top(); pq.pop();
			int d = front.first, u = front.second.first, p = front.second.second;
			if (d > dist[u][p])
				continue;
			for (int i = 0; i < F[p].size(); i++)
			{
				int v = F[p][i];
				if (dist[u][p] + abs(u-v)*T[p] < dist[v][p])
				{
					dist[v][p] = dist[u][p] + abs(u-v)*T[p];
					pq.push(iii(dist[v][p], ii(v, p)));
				}
			}
			for (int np = 0; np < N; np++)
			{
				if (np != p) for (int i = 0; i < F[np].size(); i++)
				{
					int v = F[np][i];
					if (u == v && dist[u][p] + 60 < dist[u][np])
					{
						dist[u][np] = dist[u][p] + 60;
						pq.push(iii(dist[u][np], ii(u, np)));
					}
				}
			}
		}
		int ans = INF;
		for (int n = 0; n < N; n++)
			if (dist[K][n] < ans)
				ans = dist[K][n];
		if (ans == INF)
			cout << "IMPOSSIBLE" << endl;
		else 
			cout << ans << endl;
	}
}


