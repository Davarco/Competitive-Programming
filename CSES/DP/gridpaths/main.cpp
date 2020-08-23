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
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define PLIST(a, b) \
	for (int i = 0; i < b; i++) cout << setw(10) << a[i] << (i == b-1 ? '\n' : ' ');

signed main()
{
	int N;
	cin >> N;
	string grid[N];
	for (int n = 0; n < N; n++)
		cin >> grid[n];

	int dp[N][N];
	for (int r = 0; r < N; r++) 
		for (int c = 0; c < N; c++) 
			dp[r][c] = -INF;
	for (int r = 0; r < N && grid[r][0] != '*'; r++)
		dp[r][0] = 1;
	for (int c = 0; c < N && grid[0][c] != '*'; c++)
		dp[0][c] = 1;
	for (int n = 1; n < N; n++)
	{
		for (int r = n; r < N; r++)
			if (grid[r][n] != '*')
				dp[r][n] = (max(dp[r-1][n], 0LL) + max(dp[r][n-1], 0LL)) % MOD;
		for (int c = n; c < N; c++)
			if (grid[n][c] != '*')
				dp[n][c] = (max(dp[n-1][c], 0LL) + max(dp[n][c-1], 0LL)) % MOD;
	}
	if (dp[N-1][N-1] < 0)
		cout << 0 << endl;
	else
		cout << dp[N-1][N-1] << endl;
}

