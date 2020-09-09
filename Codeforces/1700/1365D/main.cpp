#include <bits/stdc++.h>
/*
 * Basic Runtimes Table:
 * +-----+-----------------+
 * |  n  | Worst Algorithm |
 * +-----+-----------------+
 * | 11  | O(n!), O(n^6)   |
 * | 18  | O(2^n * n^2)    |
 * | 22  | O(2^n * n)      |
 * | 100 | O(n^4)          |
 * | 400 | O(n^3)          |
 * | 2K  | O(n^2 log n)    |
 * | 10K | O(n^2)          |
 * | 1M  | O(n log n)      |
 * +-----+-----------------+
 *
 * Lower Bound: First >=, Upper Bound: First >
 */
using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define endl '\n'
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int T, N, M;
int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

bool is_valid(int r, int c)
{
	return r >= 0 && r < N && c >= 0 && c < M;
}

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		bool no = false;
		vector<string> maze(N);
		for (int n = 0; n < N; n++)
			cin >> maze[n];
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
				if (maze[n][m] == 'B')
					for (int i = 0; i < 4; i++)
						if (is_valid(n+dr[i], m+dc[i]))
							if (maze[n+dr[i]][m+dc[i]] == '.')
								maze[n+dr[i]][m+dc[i]] = '#';
							else if (maze[n+dr[i]][m+dc[i]] == 'G')
								no = true;
		if (no)
		{
			cout << "No" << endl;
			continue;
		}

		bool reach[N][M];
		memset(reach, false, sizeof(reach));
		queue<ii> q;
		if (maze[N-1][M-1] != '#')
			q.push(ii(N-1, M-1));
		while (q.size() > 0)
		{
			ii now = q.front(); q.pop();
			int r = now.first, c = now.second;
			if (reach[r][c])
				continue;
			reach[r][c] = true;
			for (int i = 0; i < 4; i++)
				if (is_valid(r+dr[i], c+dc[i]) && maze[r+dr[i]][c+dc[i]] != '#')
					q.push(ii(r+dr[i], c+dc[i]));
		}

		for (int r = 0; r < N; r++)
			for (int c = 0; c < M; c++)
			{
				if (maze[r][c] == 'G' && !reach[r][c])
					no = true;
				else if (maze[r][c] == 'B' && reach[r][c])
					no = true;
			}
		if (no)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}

