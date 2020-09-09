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
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int N, A, B, C;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int n = 0; n < N; n++)
	{
		cin >> A >> B >> C;

		vi dp0(64);
		dp0[0] = B;
		for (int i = 1; i < 64; i++)
			dp0[i] = (dp0[i-1] * dp0[i-1]) % (MOD-1);
		int ans0 = 1;
		for (int i = 0; i < 64; i++)
			if ((C >> i) & 1 == 1)
				ans0 = (ans0 * dp0[i]) % (MOD-1);

		vi dp1(64);
		dp1[0] = A;
		for (int i = 1; i < 64; i++)
			dp1[i] = (dp1[i-1] * dp1[i-1]) % MOD;
		int ans1 = 1;
		for (int i = 0; i < 64; i++)
			if ((ans0 >> i) & 1 == 1)
				ans1 = (ans1 * dp1[i]) % MOD;

		cout << ans1 << endl;
	}
}

