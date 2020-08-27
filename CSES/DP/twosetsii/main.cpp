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
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int N, X;
int dp[500][62626];

signed main()
{
	cin >> N;
	X = N*(N+1)/2;
	if (X % 2 == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	else
		X /= 2;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int n = 1; n < N; n++)
	{
		for (int x = 0; x <= X; x++)
		{
			dp[n][x] = dp[n-1][x];
			if (x-n >= 0)
				dp[n][x] = (dp[n][x] + dp[n-1][x-n]) % MOD;
		}
	}
	cout << dp[N-1][X] << endl;
}

