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
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int N, M;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	map<int, int> H;
	vi T(M);
	for (int n = 0; n < N; n++)
	{
		int h;
		cin >> h;
		H[h]++;
	}
	for (int m = 0; m < M; m++)
		cin >> T[m];

	for (int t = 0; t < T.size(); t++)
	{
		auto it = H.upper_bound(T[t]);
		if (it == H.begin())
		{
			cout << -1 << endl;
			continue;
		}
		else
			it--;
		cout << it->first << endl;
		H[it->first]--;
		if (H[it->first] == 0)
			H.erase(it);
	}
}

