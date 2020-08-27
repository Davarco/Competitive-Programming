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

	vvi dp0(N, vi(N));
	vvi dp1(N, vi(N));
	for (int n = 0; n < N; n++)
		dp0[0][n] = X[n], dp1[0][n] = 0;
	for (int n = 1; n < N; n++)
		for (int i = 0; i < N-n; i++)
		{
			int a = X[i] + dp1[n-1][i+1], b = X[i+n] + dp1[n-1][i];
			if (a > b)
				dp0[n][i] = a, dp1[n][i] = dp0[n-1][i+1];
			else
				dp0[n][i] = b, dp1[n][i] = dp0[n-1][i];
		}
	cout << dp0[N-1][0] << endl;
}

