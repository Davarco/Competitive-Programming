#include <bits/stdc++.h>

using namespace std;

int C, N, M;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 100000000

int main()
{
	cin >> C;
	for (int c = 0; c < C; c++)
	{
		cin >> N >> M;
		vii G[N];
		for (int m = 0; m < M; m++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			G[a].push_back(ii(b, c));
		}	

		vi dist(N, INF);
		dist[0] = 0;
		for (int n = 0; n < N-1; n++)
			for (int u = 0; u < N; u++)
				for (int i = 0; i < G[u].size(); i++)
					dist[G[u][i].first] = min(dist[G[u][i].first], dist[u] + G[u][i].second);

		int negative = false;
		for (int u = 0; u < N; u++)
			for (int i = 0; i < G[u].size(); i++)
				if (dist[G[u][i].first] > dist[u] + G[u][i].second)
					negative = true;

		cout << (negative ? "possible" : "not possible") << endl;
	}
}
