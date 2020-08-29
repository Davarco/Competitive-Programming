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

int T, N, K, Z;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K >> Z;
		vi A(N);
		for (int n = 0; n < N; n++)
			cin >> A[n];

		vi dp(N);
		for (int i = 1; i < N; i++)
			dp[i] = max(dp[i-1], A[i] + A[i-1]);

		vi sum(N);
		sum[0] = A[0];
		for (int i = 1; i < N; i++)
			sum[i] = sum[i-1] + A[i];

		int best = sum[K];
		for (int z = 1; z <= Z; z++)
		{
			int end0 = K - z*2;
			if (end0 > 0)
				best = max(best, sum[end0] + z*dp[end0]);
			int end1 = K - z*2 + 1;
			if (end1 > 0)
				best = max(best, sum[end1] + A[end1-1] + (z-1)*dp[end1]);
		}
		cout << best << endl;
	}
}

