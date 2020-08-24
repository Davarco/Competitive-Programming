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
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');

int N, M;

signed main()
{
	cin >> N >> M;
	int A[N];
	for (int n = 0; n < N; n++)
		cin >> A[n];
	int dp[N][M+1];
	memset(dp, 0, sizeof(dp));
	if (A[0] == 0)
		for (int m = 1; m <= M; m++)
			dp[0][m] = 1;
	else
		dp[0][A[0]] = 1;
	for (int n = 1; n < N; n++)
		if (A[n] != 0)
		{
			dp[n][A[n]] = (dp[n][A[n]] + dp[n-1][A[n]]) % MOD;
			dp[n][A[n]] = (dp[n][A[n]] + (A[n] != 1 ? dp[n-1][A[n]-1] : 0)) % MOD;
			dp[n][A[n]] = (dp[n][A[n]] + (A[n] != M ? dp[n-1][A[n]+1] : 0)) % MOD;
		}
		else
		{
			for (int m = 1; m <= M; m++)
			{
				dp[n][m] = (dp[n][m] + dp[n-1][m]) % MOD;
				dp[n][m] = (dp[n][m] + (m != 1 ? dp[n-1][m-1] : 0)) % MOD;
				dp[n][m] = (dp[n][m] + (m != M ? dp[n-1][m+1] : 0)) % MOD;
			}
		}
	int sum = 0;
	for (int m = 1; m <= M; m++)
		sum = (sum + dp[N-1][m]) % MOD;
	cout << sum << endl;
}

