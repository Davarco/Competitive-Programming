#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 100000000

int N;

int main()
{
	while (scanf("%d\n", &N) != EOF)
	{
		if (N == -1)
			break;
		vi E(100, 0);
		vi G[100], U[100];
		for (int n = 0; n < N; n++)
		{
			string in; 
			getline(cin, in);
			stringstream ss(in);
			int D;
			ss >> E[n] >> D;
			for (int d = 0; d < D; d++)
			{
				int x;
				ss >> x, x -= 1;
				G[n].push_back(x);
				U[n].push_back(false);
			}
		}

		/*
		vi dist(100, INF);
		for (int n = 0; n < N-1; n++)
			for (int u = 0; u < N; u++)
				for (int i = 0; i < G[u].size(); i++)
					dist[G[u][i]] = max(dist[G[u][i]], dist[u] + E[G[u][i]]);

		vi positive;
		for (int u = 0; u < N; u++)
			for (int i = 0; i < G[u].size(); i++)
				if (dist[G[u][i]] < dist[u] + E[G[u][i]])
					positive.push_back(u);

		queue<int> q;
		for (int i = 0; i < positive.size(); i++)
			q.push(positive[i]);
		vi vist(100, false);
		while (q.size() > 0)
		{
			int u = q.front(); q.pop();
			vist[u] = true;
			for (int i = 0; i < G[u].size(); i++)
				if (!vist[G[u][i]])
					q.push(G[u][i]);
		}
		*/

		priority_queue<ii> pq;
		pq.push(ii(100, 0));
		int found = false;
		while (pq.size() > 0)
		{
			ii top = pq.top(); pq.pop();
			int e = top.first, u = top.second;
			if (u == N-1)
			{
				found = true;
				break;
			}
			for (int i = 0; i < G[u].size(); i++)
			{
				if (e + E[G[u][i]] > 0 && U[u][i] == false)
				{
					U[u][i] = true;
					pq.push(ii(e + E[G[u][i]], G[u][i]));
				}
			}
		}

		if (found)
			cout << "winnable" << endl;
		else
			cout << "hopeless" << endl;
	}
}
