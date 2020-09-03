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

int N, Q;
vi G[200000], order, size;

int dfs(int u)
{
	order.push_back(u);
	if (G[u].size() == 0)
	{
		size[u] = 1;
		return 1;
	}
	for (int i = 0; i < G[u].size(); i++)
		size[u] += dfs(G[u][i]);
	++size[u];
	return size[u];
}

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> Q;
	for (int n = 1; n < N; n++)
	{
		int superior;
		cin >> superior, --superior;
		G[superior].push_back(n);
	}
	size.assign(N, 0);
	dfs(0);
	vi index(N);
	for (int i = 0; i < N; i++)
		index[order[i]] = i;
	for (int q = 0; q < Q; q++)
	{
		int u, k;
		cin >> u >> k, --u, --k;
		int pos = index[u] + k;
		if (k < size[u])
			cout << order[pos] + 1 << endl;
		else
			cout << -1 << endl;
	}
}

