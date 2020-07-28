#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <iomanip>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int M, N;
int grid[50][50];

int good(int r, int c)
{
	return r > 0 && c > 0 && r < M && c < N && !grid[r][c] && !grid[r-1][c] && !grid[r][c-1] &&
		!grid[r-1][c-1];
}

int main()
{
	while (cin >> M >> N)
	{
		if (M == 0 && N == 0)
			break;
		for (int m = 0; m < M; m++) for (int n = 0; n < N; n++) cin >> grid[m][n];

		int a, b, c, d;
		ii start, end;
		cin >> a >> b >> c >> d;
		start = ii(a, b), end = ii(c, d);
		
		string in;
		cin >> in;
		int start_dir = (in == "north" ? 0 : (in == "east" ? 1 : (in == "south" ? 2 : 3)));

		int distance[M+1][N+1][4];
		for (int a = 0; a < M+1; a++) for (int b = 0; b < N+1; b++) for (int c = 0; c < 4; c++)
			distance[a][b][c] = -1;
		queue<iii> q;
		distance[start.first][start.second][start_dir] = 0, q.push(iii(start_dir, start));
		while (q.size() > 0)
		{
			iii u = q.front(); q.pop();
			int dir = u.first, r = u.second.first, c = u.second.second;
			int L = (dir-1) % 4; if (L < 0) L += 4;
			int R = (dir+1) % 4;
			if (distance[r][c][L] == -1)
			{
				distance[r][c][L] = distance[r][c][dir] + 1;
				q.push(iii(L, ii(r, c)));
			}
			if (distance[r][c][R] == -1)
			{
				distance[r][c][R] = distance[r][c][dir] + 1;
				q.push(iii(R, ii(r, c)));
			}

			int prev[4];
			for (int n = 0; n < 4; n++) prev[n] = true;
			for (int n = 1; n <= 3; n++)
			{
				if (prev[dir])
				{
					prev[dir] = false;
					if (dir == 0 && good(r-n, c))
					{
						if (distance[r-n][c][dir] == -1)
						{
							distance[r-n][c][dir] = distance[r][c][dir] + 1;
							q.push(iii(dir, ii(r-n, c)));
						}
						prev[dir] = true;
					}
					if (dir == 1 && good(r, c+n))
					{
						if (distance[r][c+n][dir] == -1)
						{
							distance[r][c+n][dir] = distance[r][c][dir] + 1;
							q.push(iii(dir, ii(r, c+n)));
						}
						prev[dir] = true;
					}
					if (dir == 2 && good(r+n, c))
					{
						if (distance[r+n][c][dir] == -1)
						{
							distance[r+n][c][dir] = distance[r][c][dir] + 1;
							q.push(iii(dir, ii(r+n, c)));
						}
						prev[dir] = true;
					}
					if (dir == 3 && good(r, c-n))
					{
						if (distance[r][c-n][dir] == -1)
						{
							distance[r][c-n][dir] = distance[r][c][dir] + 1;
							q.push(iii(dir, ii(r, c-n)));
						}
						prev[dir] = true;
					}
				}
			}
		}

		int best = INT_MAX;
		for (int i = 0; i < 4; i++)
			best = min(best, distance[end.first][end.second][i]);
		cout << best << endl;
	}
}
