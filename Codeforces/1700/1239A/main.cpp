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
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define endl '\n'
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int N, M;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	vi dp0(N);
	dp0[0] = 2;
	if (N > 1)
	{
		dp0[1] = 4;
		for (int n = 2; n < N; n++)
			dp0[n] = (dp0[n-1] + dp0[n-2]) % MOD;
	}
	vi dp1(M);
	dp1[0] = 2;
	if (M > 1)
	{
		dp1[1] = 4;
		for (int m = 2; m < M; m++)
			dp1[m] = (dp1[m-1] + dp1[m-2]) % MOD;
	}
	cout << (dp0[N-1] + dp1[M-1] - 2) % MOD << endl;
}

