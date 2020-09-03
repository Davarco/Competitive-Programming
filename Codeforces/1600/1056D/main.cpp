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

int N;
vi G[100000], V, colors;

int dfs(int u)
{
	V[u] = true;
	int total = 0;
	for (int v: G[u])
		if (!V[v])
			total += dfs(v);
	if (!total)
	{
		colors[u] = 1;
		return 1;
	}
	else
	{
		colors[u] = total;
		return total;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int n = 1; n < N; n++)
	{
		int b;
		cin >> b, b--;
		G[n].push_back(b), G[b].push_back(n);
	}

	V.assign(N, 0), colors.assign(N, 0);
	dfs(0);
	sort(colors.begin(), colors.end());
	PLIST(colors, N);
}

