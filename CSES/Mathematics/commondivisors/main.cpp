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

int N;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;
	vi X(N);
	for (int n = 0; n < N; n++)
		cin >> X[n];
	unordered_map<int, int> um;
	for (int n = 0; n < N; n++)
	{
		for (int x = 1; x*x <= X; x++)
			if (X % x == 0)
				um[x]++, um[X / x]++;
	}
	int best = 0;
	for (auto it = um.begin(); it != um.end(); it++)
		if (it->second > 1 && it->first > best)
			best = it->first;
	cout << best << endl;
}

