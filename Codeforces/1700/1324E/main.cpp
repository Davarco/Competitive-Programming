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

int N, H, L, R;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> H >> L >> R;
	vi A(N);
	for (int n = 0; n < N; n++)
		cin >> A[n];

	vvi dp(N, vi(H, -INF));
	dp[0][A[0]] = (A[0] >= L && A[0] <= R), dp[0][A[0]-1] = (A[0]-1 >= L && A[0]-1 <= R);
	for (int n = 1; n < N; n++)
	{
		for (int i = 0; i < H; i++)
		{
			if (dp[n-1][i] != -INF)
			{
				int nx0 = (i + A[n]) % H;
				int cn0 = dp[n-1][i] + (nx0 >= L && nx0 <= R);
				dp[n][nx0] = max(dp[n][nx0], cn0);

				int nx1 = (i + A[n] - 1) % H;
				int cn1 = dp[n-1][i] + (nx1 >= L && nx1 <= R);
				dp[n][nx1] = max(dp[n][nx1], cn1);
			}
		}
	}
	int best = 0;
	for (int h = 0; h < H; h++)
		best = max(best, dp[N-1][h]);
	cout << best << endl;
}

