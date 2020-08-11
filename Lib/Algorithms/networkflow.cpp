#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define INF 100000000

int res[40][40], MF, F, N, S, D; vi G[40], P;
void augment(int v, int min_edge)
{
	if (v == S)
	{
		F = min_edge;
		return;
	}
	else if (P[v] != -1)
		augment(P[v], min(min_edge, res[P[v]][v])), res[P[v]][v] -= F, res[v][P[v]] += F;
}
void edmondskarp()
{
	memset(res, 0, sizeof(res));
	cin >> N >> S >> D;
	for (int u = 0; u < N; u++)
	{
		int a;
		cin >> a;
		for (int i = 0; i < a; i++)
		{
			int v, w;
			cin >> v >> w;
			res[u][v] = w;
			G[u].push_back(v);
		}
	}

	MF = 0;
	while (true)
	{
		F = 0;
		vi dis(N, INF); dis[S] = 0; queue<int> q; q.push(S); P.assign(N, -1);
		while (q.size() > 0)
		{
			int u = q.front(); q.pop();
			if (u == D)
				break;
			for (int i = 0; i < N; i++)
			{
				int v = G[u][i];
				if (res[u][v] > 0 && dis[v] == INF)
					dis[v] = dis[u] + 1, q.push(v), P[v] = u;
			}
		}
		augment(D, INF);
		if (F == 0)
			break;
		MF += F;
	}
	cout << MF << endl;
}

int main()
{
	edmondskarp();
}
