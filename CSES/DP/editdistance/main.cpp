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

int N, M;
string A, B;

/*
 * This wasn't super intuitive for me, so I'm adding some comments.
 */
signed main()
{
	cin >> A >> B;
	N = A.size(), M = B.size();
	int dp[N+1][M+1];
	memset(dp, 0, sizeof(dp));
	for (int n = 1; n <= N; n++)
		dp[n][0] = n;
	for (int m = 1; m <= M; m++)
		dp[0][m] = m;
	for (int n = 1; n <= N; n++)
		for (int m = 1; m <= M; m++)
		{
			// DP state describes number of moves needed to change A[:n] to B[:m].

			/*
			 * Remove A[n]. We can change the A[:n-1] to B[m] in dp[n-1][m] moves. We then add 1 
			 * because removing A[n] takes a move.
			 */
			int a = dp[n-1][m] + 1;

			/*
			 * Add B[m] to A. We can change A[:n] to B[:m-1] in dp[n][m-1] moves. We then add 1 
			 * because adding B[m] to A takes a move.
			 */
			int b = dp[n][m-1] + 1;

			/*
			 * Change A[n] to B[m]. We can change A[:n-1] to B[:m-1] in dp[n-1][m-1] moves. We then 
			 * add 1 because changing A[n] to B[m] takes a move.
			 */
			int c = dp[n-1][m-1] + 1;

			/*
			 * If A[n] and B[m] are the same, we don't need to make a move. 
			 */
			int d = (A[n-1] == B[m-1] ? dp[n-1][m-1] : INF);

			dp[n][m] = min({ a, b, c, d });
		}
	cout << dp[N][M] << endl;
}

