#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int R, C, N;
vvi grid;
vii nextsq = { ii(0, 1), ii(1, 0), ii(0, -1), ii(-1, 0) };

int main()
{
	while (cin >> R >> C)
	{
		if (R == 0 && C == 0)
			break;
		else
			grid.assign(R, vi(C));
		cin >> N;
		for (int n = 0; n < N; n++)
		{
			int r, p, c;
			cin >> r >> p;
			for (int i = 0; i < p; i++)
			{
				cin >> c;
				grid[r][c] = 1;
			}
		}

		int a, b;
		cin >> a >> b;
		ii start = ii(a, b);
		cin >> a >> b;
		ii end = ii(a, b);

		vvi dist(R, vi(C, -1));
		queue<ii> q;
		dist[start.first][start.second] = 0, q.push(start);
		while (q.size() > 0)
		{
			ii u = q.front(); q.pop();
			for (int i = 0; i < nextsq.size(); i++)
			{
				int vr = u.first+nextsq[i].first, vc = u.second+nextsq[i].second;
				if (vr > -1 && vc > -1 && vr < R && vc < C && dist[vr][vc] == -1 && !grid[vr][vc])
				{
					dist[vr][vc] = dist[u.first][u.second] + 1;
					q.push(ii(vr, vc));
				}
			}
		}

		cout << dist[end.first][end.second] << endl;
	}
}
