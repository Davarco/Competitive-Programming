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

int N;

signed main()
{
	cin >> N;
	int X[N+1];
	memset(X, 0, sizeof(X));
	for (int n = 1; n <= N; n++)
		cin >> X[n];

	int M = 0;
	for (int x = 0; x <= N; x++)
		M += X[x];
	int dp[N+1][M+1];
	memset(dp, false, sizeof(dp));
	for (int n = 0; n <= N; n++)
		dp[n][0] = true;
	for (int x = 1; x <= N; x++)
		for (int m = 1; m <= M; m++)
			if (m-X[x] >= 0 && dp[x-1][m-X[x]])
				dp[x][m] = true;
			else
				dp[x][m] = dp[x-1][m];

	vi ans;
	for (int m = 1; m <= M; m++)
		if (dp[N][m])
			ans.push_back(m);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << (i == ans.size()-1 ? '\n' : ' ');
}

