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
		reverse(R.begin(), R.end());

		int red, blue;

		red = 0, blue = 0;
		map<ii, int> needed;
		needed[ii(red, blue)] = N;
		cout << "a" << endl;
		for (int n = 0; n < N; n++)
			red += (L[n] == 1), blue += (L[n] == 2), needed[ii(red, blue)] = N-n-1, cout << red <<
				" " << blue << endl;
		
		int best = N*2;
		red = 0, blue = 0;

		cout << "b" << endl;
		for (int n = 0; n < N; n++)
		{
			red += (R[n] == 1), blue += (R[n] == 2);
			cout << red << " " << blue << endl;
			int removed = N-n-1;
			if (needed.count(ii(red, blue)) == 0)
				continue;
			int other = needed[ii(red, blue)];
			best = min(best, removed + other);
		}
		cout << best << endl;
	}
}

