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
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int N;

signed main()
{
	cin >> N;
	vi X(N);
	for (int n = 0; n < N; n++)
		cin >> X[n];
	/*
	vi dp(N, 1);
	for (int n = 0; n < N; n++)
		for (int i = 0; i < n; i++)
			if (X[n] > X[i])
				dp[n] = max(dp[n], dp[i] + 1);
	cout << dp[N-1] << endl;
	*/
	vi dp(N, LLONG_MAX);
	dp[0] = X[0];
	for (int n = 1; n < N; n++)
	{
		int i = lower_bound(dp.begin(), dp.end(), X[n]) - dp.begin();
		dp[i] = X[n];
	}
	int best = 0;
	for (int i = 0; i < N; i++)
		if (dp[i] != LLONG_MAX)
			best = i+1;
	cout << best << endl;
}

