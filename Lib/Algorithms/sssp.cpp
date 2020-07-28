#include <iostream>
#include <algorithm>
#include <vector> 
#include <tuple>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF 1000000000

// SSSP on an Unweighted Graph
// O(V + E)
// Straightforward implementation with BFS, keep track of distance instead of visited.

// O((V + E) log V)
// Uses lazy deletion so the check where (d > dist[u]) is critical.
void dijkstra_v1()
{
	vvii G = {
		{ ii(4, 1) }, { ii(3, 3), ii(4, 6) }, { ii(0, 6), ii(1, 2), ii(3, 7) }, { ii(4, 5) }, {}
	};
	
	int V = G.size(), S = 2;
	vi dist(V, INF);
	priority_queue<ii, vii, greater<ii>> pq;
	
	dist[S] = 0, pq.push(ii(0, S));
	while (pq.size() > 0)
	{
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u])
			continue;
		for (int i = 0; i < G[u].size(); i++)
		{
			ii v = G[u][i];
			if (dist[u] + v.second < dist[v.first])
			{
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	for (int i = 0; i < V; i++) cout << dist[i] << (i == V-1 ? '\n' : ' ');
}

// O(VE)
// Best for small graphs with possible negative cycles.
void bellmanford()
{
	vvii G = {
		{ ii(1, 1000) }, { ii(2, 15) }, { ii(1, -42) }
	};

	int V = G.size(), S = 0;
	vi dist(V, INF);
	dist[S] = 0;
	for (int n = 0; n < V-1; n++)
		for (int u = 0; u < V; u++)
			for (int i = 0; i < G[u].size(); i++)
			{
				ii v = G[u][i];
				dist[v.first] = min(dist[v.first], dist[u]+v.second);
			}
	for (int i = 0; i < V; i++) cout << dist[i] << (i == V-1 ? '\n' : ' ');

	int negative = false;
	for (int u = 0; u < V; u++)
		for (int i = 0; i < G[u].size(); i++)
		{
			ii v = G[u][i];
			if (dist[v.first] > dist[u]+v.second)
				negative = true;
		}
	cout << (negative ? "Negative exists." : "Negative doesn't exist.") << endl;
}

int main()
{
	dijkstra_v1();
	bellmanford();
}
