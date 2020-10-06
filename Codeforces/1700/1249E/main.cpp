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
#define endl '\n'
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int N, C;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> C;
	vi A(N);
	vi B(N);
	for (int n = 1; n < N; n++)
		cin >> A[n];
	for (int n = 1; n < N; n++)
		cin >> B[n];
	
	vi dp0(N);
	vi dp1(N);
	dp0[0] = 0, dp1[0] = INF;
	for (int n = 1; n < N; n++)
	{
		dp0[n] = min(dp0[n-1] + A[n], dp1[n-1] + A[n]);
		dp1[n] = min(dp0[n-1] + B[n] + C, dp1[n-1] + B[n]);
	}
	for (int n = 0; n < N; n++)
		cout << min(dp0[n], dp1[n]) << (n == N-1 ? '\n' : ' ');
}

