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

int T, N;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vi L(N);
		vi R(N);
		for (int n = 0; n < N; n++)
			cin >> L[n];
		for (int n = 0; n < N; n++)
			cin >> R[n];
		reverse(L.begin(), L.end());

		int netR = 0;
		for (int n = 0; n < N; n++)
			if (R[n] == 1)
				netR++;
			else
				netR--;
		unordered_map<int, int> best;
		best[netR] = 0;
		for (int n = 0; n < N; n++)
		{
			if (R[n] == 1)
				netR--;
			else
				netR++;
			if (best.count(netR) == 0)
				best[netR] = n+1;
		}

		int netL = 0, ans = N*2;
		for (int n = 0; n < N; n++)
			if (L[n] == 1)
				netL++;
			else
				netL--;
		if (best.count(-netL) > 0)
			ans = min(ans, best[-netL]);
		for (int n = 0; n < N; n++)
		{
			if (L[n] == 1)
				netL--;
			else
				netL++;
			if (best.count(-netL) > 0)
				ans = min(ans, best[-netL]+n+1);
		}
		cout << ans << endl;
	}
}

