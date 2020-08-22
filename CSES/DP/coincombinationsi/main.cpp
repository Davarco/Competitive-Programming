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

#define MOD 1000000007
#define INF 100000000
#define PLIST(a, b) \
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');
#define PLIST2(a, b) \
	for (int i = 0; i < b; i++) cout << a << (i == b-1 ? '\n' : ' ');

int N, X;

signed main()
{
	cin >> N >> X;
	vi C(N);
	for (int n = 0; n < N; n++)
		cin >> C[n];
	vi dp(X+1, 0);
	dp[0] = 1;
	for (int x = 0; x <= X; x++)
		for (int c = 0; c < N; c++)
			if (x-C[c] >= 0)
				dp[x] = (dp[x] + dp[x-C[c]]) % MOD;
	cout << dp[X] << endl;
}

