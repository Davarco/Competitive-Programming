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
 *
 * Lower Bound: First >=, Upper Bound: First >
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

int T, N, P, K;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> P >> K;
		vi A(N);
		for (int n = 0; n < N; n++)
			cin >> A[n];
		sort(A.begin(), A.end());

		vi dp(K);
		dp[0] = P;
		for (int i = 1; i < K; i++)
			dp[i] = dp[i-1] - A[i-1];

		int best = 0;
		for (int s = 0; s < K; s++)
		{
			int p = dp[s], i = s+K-1, count = s;
			if (p < 0)
				continue;
			while (i < N && p - A[i] >= 0)
				p -= A[i], i += K, count += K;
			best = max(best, count);
		}

		cout << best << endl;
	}
}

