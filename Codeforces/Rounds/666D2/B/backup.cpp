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

int N;

int POW(int i, int N)
{
	int a = 1;
	while (N--)
		a *= i;
	return a;
}

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;
	vi A(N);
	for (int n = 0; n < N; n++)
		cin >> A[n];
	sort(A.begin(), A.end());

	int i;
	if (N <= 30)
	{
		/*
		for (i = 1; POW(i, N-1) <= A[N-1]; i++);
		int d0 = abs(A[N-1] - POW(i, N-1)), d1 = abs(POW(i+1, N-1) - A[N-1]);
		if (d1 < d0)
			i++;
		*/
	}
	else
		i = 1;

	int best = LLONG_MAX;
	for (int a = 1; a <= i; a++)
	{
		int cur = 1, diff = 0;
		for (int n = 0; n < N; n++)
		{
			diff += abs(A[n] - cur);
			cur *= a;
		}
		best = min(best, diff);
	}
	cout << best << endl;
}

