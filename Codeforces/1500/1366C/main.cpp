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
 */
using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define PLIST(a, b) \
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');

int T, N, M;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		int mat[N][M];
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
				cin >> mat[n][m];
		int Z[N+M-1], O[N+M-1];
		memset(Z, 0, sizeof(Z)), memset(O, 0, sizeof(O));
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
				if (mat[n][m] == 0)
					Z[n+m]++;
				else
					O[n+m]++;
		int count = 0;
		for (int n = 0; n < (N+M-1)/2; n++)
		{
			int z = Z[n] + Z[N+M-n-2], o = O[n] + O[N+M-n-2];
			count += min(z, o);	
		}
		cout << count << endl;
	}
}

