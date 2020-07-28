#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF 100000000

int T, N, M;
int dir[4][2] = {{ 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }};

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		int grid[N][M];
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
				cin >> grid[n][m];

		vi dist(N*M, INF);
		priority_queue<ii, vii, greater<ii>> pq;

		dist[0] = grid[0][0], pq.push(ii(dist[0], 0));
		while (pq.size() > 0)
		{
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second, r = u / M, c = u % M;
			if (d > dist[u])
				continue;
			for (int i = 0; i < 4; i++)
			{
				int rn = r+dir[i][0], cn = c+dir[i][1], v = rn*M + cn;
				if (rn >= 0 && cn >= 0 && rn < N && cn < M && dist[u] + grid[rn][cn] < dist[v])
				{
					dist[v] = dist[u] + grid[rn][cn];
					pq.push(ii(dist[v], v));
				}
			}
		}
		cout << dist[N*M-1] << endl;
	}
}
