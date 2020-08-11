#include <bits/stdc++.h>

using namespace std;

#define INF 100000000

int T, N, R;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> R;
		int G[N][N];
		for (int a = 0; a < N; a++)
			for (int b = 0; b < N; b++)
				G[a][b] = (a == b ? 0 : INF);
		for (int r = 0; r < R; r++)
		{
			int u, v;
			cin >> u >> v;
			G[u][v] = 1, G[v][u] = 1;
		}
		for (int n = 0; n < N; n++)
			for (int a = 0; a < N; a++)
				for (int b = 0; b < N; b++)
					G[a][b] = min(G[a][b], G[a][n] + G[n][b]);

		int start, dest;
		cin >> start >> dest;

		int minimum = 0;
		for (int n = 0; n < N; n++)
			minimum = max(minimum, G[start][n] + G[n][dest]);
		printf("Case %d: %d\n", t+1, minimum);
	}
}
