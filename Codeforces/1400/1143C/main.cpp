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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define PLIST(a, b) \
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');

int N, R;
vi P, G, safe;

signed main()
{
	cin >> N;
	P.assign(N, 0), G.assign(N, 0), safe.assign(N, false);
	for (int n = 0; n < N; n++)
	{
		int a, b;
		cin >> a >> b;
		if (a != -1) 
			P[n] = --a;
		else
			P[n] = -1;
		G[n] = b;
		if (b == 0 && a != -1)
			safe[a] = true;
	}
	vi res;
	for (int n = 0; n < N; n++)
		if (!safe[n] && G[n] == 1)
			res.push_back(n+1);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << (i == res.size()-1 ? '\n' : ' ');
	if (res.size() == 0)
		cout << -1 << endl;
}

