#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int T, N, M;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		vvi grid(N, vi(M));
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
				cin >> grid[n][m];

		vvi neighbors(N, vi(M));
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
			{
				int count = 0;
				if (n != 0)
					count += 1;
				if (m != 0)
					count += 1;
				if (n < N-1)
					count += 1;
				if (m < M-1)
					count += 1;
				neighbors[n][m] = count;
			}

		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
				if (grid[n][m] > neighbors[n][m])
				{
					cout << "NO" << endl;
					goto end;
				}

		cout << "YES" << endl;
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
				cout << neighbors[n][m] << (m == M-1 ? '\n' : ' ');

end:
		int a;
	}
}

