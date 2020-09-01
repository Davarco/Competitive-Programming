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

int N, M;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vi A(N);
	for (int n = 0; n < N; n++)
		cin >> A[n];

	if (N > M)
	{
		cout << 0 << endl;
		return 0;
	}
	else
	{
		int ans = 1;
		for (int a = 0; a < N; a++)
			for (int b = 0; b < a; b++)
				ans = (ans * abs(A[a] - A[b])) % M;
		cout << ans << endl;
	}
}

