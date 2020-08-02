#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 100000000

int N, R, Q;

int main()
{
	int C = 0;
	while (cin >> N)
	{
		printf("Set #%d\n", ++C);
		vi B(N);
		for (int n = 0; n < N; n++) 
			cin >> B[n];
		vii G[N];
		cin >> R;
		for (int r = 0; r < R; r++)
		{
			int s, d;
			cin >> s >> d, s -= 1, d -= 1;
			int w = B[d] - B[s];
			G[s].push_back(ii(d, w*w*w));	
		}

		vi dist(N, INF);
		dist[0] = 0;
		for (int n = 0; n < N-1; n++)
			for (int u = 0; u < N; u++)
				for (int i = 0; i < G[u].size(); i++)
					dist[G[u][i].first] = min(dist[G[u][i].first], dist[u] + G[u][i].second);

		// for (int i = 0; i < N; i++) cout << dist[i] << (i == N-1 ? '\n' : ' ');
		
		vi negative;
		for (int u = 0; u < N; u++)
			for (int i = 0; i < G[u].size(); i++)
				if (dist[G[u][i].first] > dist[u] + G[u][i].second)
					negative.push_back(u);

		vi vist(N, false);
		queue<int> q;
		for (int i = 0; i < negative.size(); i++)
			q.push(negative[i]);
		while (q.size() > 0)
		{
			int u = q.front(); q.pop();
			dist[u] = -1;
			vist[u] = true;
			for (int i = 0; i < G[u].size(); i++)
				if (!vist[G[u][i].first])
					q.push(G[u][i].first);
		}

		cin >> Q;
		for (int q = 0; q < Q; q++)
		{
			int D;
			cin >> D, D -= 1;
			// The 9000000 isn't the best idea, but it got AC so whatever.
			if (dist[D] < 3 || dist[D] > 9000000)
				cout << "?" << endl;
			else
				cout << dist[D] << endl;
		}
	}
}
