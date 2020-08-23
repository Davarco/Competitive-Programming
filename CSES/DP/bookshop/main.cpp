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

int N, X;

signed main()
{
	cin >> N >> X;
	vi H(N+1);
	vi S(N+1);
	for (int n = 1; n <= N; n++)
		cin >> H[n];
	for (int n = 1; n <= N; n++)
		cin >> S[n];
	int dp[N+1][X+1];
	memset(dp, 0, sizeof(dp));
	for (int h = 1; h <= N; h++)
		for (int x = 0; x <= X; x++)
			if (x-H[h] >= 0)
				dp[h][x] = max(dp[h-1][x], dp[h-1][x-H[h]] + S[h]);
			else
				dp[h][x] = dp[h-1][x];
	cout << dp[N][X] << endl;
}

