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
#define PLIST2(a, b) \
	for (int i = 0; i < b; i++) cout << a << (i == b-1 ? '\n' : ' ');

int N, X;

signed main()
{
	cin >> N >> X;
	vi C(N+1);
	for (int n = 1; n <= N; n++)
		cin >> C[n];
	vvi dp(N+1, vi(X+1, 0));
	dp[0][0] = 1;
	for (int c = 1; c <= N; c++)
		for (int x = 0; x <= X; x++)
			if (x-C[c] >= 0)
				dp[c][x] = (dp[c-1][x] + dp[c][x-C[c]]) % MOD;
			else
				dp[c][x] = dp[c-1][x];
	cout << dp[N][X] << endl;
}

