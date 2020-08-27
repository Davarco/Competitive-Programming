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
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

/*
 * This is a great question. It requires some insight with graph DS and then uses DP. I tried doing
 * a set -> unordered_map but that gave me TLE on a test case - the bounds are harsh. It turns out
 * just using map and updating that was faster, good to keep in mind!
 */

int N;

signed main()
{
	cin >> N;
	int Ptemp[N][3];
	map<int, int> remap;
	for (int n = 0; n < N; n++)
	{
		int a, b, p;
		cin >> a >> b >> p;
		Ptemp[n][0] = p, Ptemp[n][1] = a, Ptemp[n][2] = b;
		remap[a], remap[b];
	}
	int M = 0;
	for (auto i = remap.begin(); i != remap.end(); i++)
		i->second = M++;

	vii P[M];
	for (int n = 0; n < N; n++)
	{
		int p = Ptemp[n][0], a = remap[Ptemp[n][1]], b = remap[Ptemp[n][2]];
		P[b].push_back(ii(a, p));
	}

	vector<LL> dp(M);
	for (int m = 0; m < M; m++)
	{
		if (m > 0)
			dp[m] = dp[m-1];
		for (int b = 0; b < P[m].size(); b++)
		{
			LL a = P[m][b].first, p = P[m][b].second, c = p + (a-1 >= 0 ? dp[a-1] : 0);
			dp[m] = max(dp[m], c);
		}
	}
	cout << dp[M-1] << endl;
}

