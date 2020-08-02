#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 100000000

int M;

int main()
{
	while (cin >> M)
	{
		if (M == 0)
			break;

		int Lid = 0;
		unordered_map<string, int> Lmap;

		string o, d; 
		cin >> o >> d;

		vii L; vector<string> W;
		for (int m = 0; m < M; m++)
		{
			string i1, i2, p; 
			cin >> i1 >> i2 >> p;
			if (Lmap.find(i1) == Lmap.end())
				Lmap[i1] = Lid++;
			if (Lmap.find(i2) == Lmap.end())
				Lmap[i2] = Lid++;
			L.push_back(ii(Lmap[i1], Lmap[i2])), W.push_back(p);	
		}

		vii edges[2002];
		for (int a = 0; a < L.size(); a++)
			for (int b = a+1; b < L.size(); b++)
				if (W[a][0] != W[b][0] && (L[a].first == L[b].first || L[a].first == L[b].second ||
							L[a].second == L[b].first || L[a].second == L[b].second))
					edges[a].push_back(ii(b, W[b].size())), edges[b].push_back(ii(a, W[a].size()));
		for (int i = 0; i < L.size(); i++)
			if (Lmap.find(o) != Lmap.end() && (Lmap[o] == L[i].first || Lmap[o] == L[i].second))
				edges[2000].push_back(ii(i, W[i].size()));
		for (int i = 0; i < L.size(); i++)
			if (Lmap.find(d) != Lmap.end() && (Lmap[d] == L[i].first || Lmap[d] == L[i].second))
				edges[i].push_back(ii(2001, 0));
		
		vi dist(2002, INF);
		priority_queue<ii, vii, greater<ii>> pq;
		dist[2000] = 0, pq.push(ii(0, 2000));
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
		if (dist[2001] != INF)
			cout << dist[2001] << endl;
		else
			cout << "impossivel" << endl;
	}
}
