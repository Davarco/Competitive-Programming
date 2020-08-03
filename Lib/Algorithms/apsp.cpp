#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF 1000000000

// O(V^3)
// Uses ADJMATRIX.
void floydwarshall()
{
	vvi G = { 
		{ 0, 2, 1, INF, 3 },
		{ INF, 0, INF, 4, INF },
		{ INF, 1, 0, INF, 1 },
		{ 1, INF, 3, 0, 5 },
		{ INF, INF, INF, INF, 0 }
	};

	int N = G.size();

	/*
	 * Concept of intermediate vertices. We start with just direct edges. Then, we let the 0th
	 * vertex to be used in-between two vertices. We increase this until the (N-1)th vertex, and
	 * then get the answer.
	 */
	/*
	for (int n = 0; n < N; n++)
		for (int a = 0; a < N; a++)
			for (int b = 0; b < N; b++)
				G[a][b] = min(G[a][b], G[a][n] + G[n][b]);
	*/

	vvi p(N, vi(N));
	for (int a = 0; a < N; a++) 
		for (int b = 0; b < N; b++) 
			p[a][b] = a;
	for (int n = 0; n < N; n++)
		for (int a = 0; a < N; a++)
			for (int b = 0; b < N; b++)
				if (G[a][n] + G[n][b] < G[a][b])
					G[a][b] = G[a][n] + G[n][b], p[a][b] = p[n][b];

	vi rpath;
	int a = 3, b = 4;
	while (a != b)
	{
		rpath.push_back(b);
		b = p[a][b];
	}
	reverse(rpath.begin(), rpath.end());
	for (int i = 0; i < rpath.size(); i++)
		cout << rpath[i] << (i == rpath.size()-1 ? '\n' : ' ');

	// Transitive Closure
	// Set direct edges to 1 in AM, and 0 otherwise.
	// G[a][b] |= (G[a][n] & G[n][b])

	// Minimax and Maximin
	// G[a][b] = min(G[a][b], max(G[a][n], G[n][b]))
	
	// Cheapest Non-Negative or Negative Cycle
	// Set G[i][i] to INF. Run FW. If G[i][i] < 0, there is a negative cycle. Otherwise, the
	// smallest positive G[i][i] < INF is the cheapest non-negative cycle.
}

int main()
{
	floydwarshall();
}
