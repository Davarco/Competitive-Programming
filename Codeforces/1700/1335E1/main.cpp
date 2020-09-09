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

int T, N;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vi A(N);
		for (int n = 0; n < N; n++)
			cin >> A[n], A[n]--;

		vvi dp(N, vi(26));
		for (int a = 0; a < N; a++)
			for (int l = 0; l < 26; l++)
				dp[a][l] = (a > 0 ? dp[a-1][l] : 0) + (A[a] == l);

		int best = 0;
		for (int l = 0; l < 26; l++)
			best = max(best, dp[N-1][l]);
		for (int a = 0; a < N; a++)
			for (int b = a; b < N; b++)
			{
				int inner = 0;
				for (int l = 0; l < 26; l++)
				{
					int temp = dp[b][l] - (a > 0 ? dp[a-1][l] : 0);
					inner = max(inner, temp);
				}
				int outer = 0;
				if (a > 0 && b < N-1)
					for (int l = 0; l < 26; l++)
						outer = max(outer, min(dp[a-1][l], dp[N-1][l] - dp[b][l]));			
				best = max(best, inner + outer*2);
			}
		cout << best << endl;
	}
}

