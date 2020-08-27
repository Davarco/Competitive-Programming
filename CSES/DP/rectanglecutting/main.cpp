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

int A, B;

signed main()
{
	cin >> A >> B;	
	int dp[A][B];
	for (int a = 0; a < A; a++)
		for (int b = 0; b < B; b++)
			dp[a][b] = INF;
	for (int n = 0; n < min(A, B); n++)
		dp[n][n] = 0;
	for (int a = 0; a < A; a++)
		dp[a][0] = a;
	for (int b = 0; b < B; b++)
		dp[0][b] = b;
	for (int a = 1; a < A; a++)
		for (int b = 1; b < B; b++)
		{
			for (int c = 0; c < a; c++)
				dp[a][b] = min(dp[a][b], dp[c][b] + dp[a-c-1][b] + 1);
			for (int c = 0; c < b; c++)
				dp[a][b] = min(dp[a][b], dp[a][c] + dp[a][b-c-1] + 1);
		}
	cout << dp[A-1][B-1] << endl;
}

