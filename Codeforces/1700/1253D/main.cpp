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

int N, M;
vi G[200000], vis, last;

int dfs(int u)
{
	if (vis[u])
		return -1;
	else
		vis[u] = true;
	int best = u;
	for (int i = 0; i < G[u].size(); i++)
		if (!vis[G[u][i]])
			best = max(best, max(dfs(G[u][i]), G[u][i]));
	last[u] = best;
	return best;
}

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int m = 0; m < M; m++)
	{
		int u, v;
		cin >> u >> v, --u, --v;
		G[u].push_back(v), G[v].push_back(u);
	}
	vis.assign(N, false), last.assign(N, -1);

	vii bounds;

	for (int i = 0; i < N; i++)
		if (!vis[i])
			bounds.push_back(ii(i, dfs(i)));

	int count = 0, last_elem = -1;
	for (int i = 0; i < bounds.size(); i++)
	{
		int a = bounds[i].first, b = bounds[i].second;
		if (a < last_elem)
			count++;
		last_elem = max(last_elem, b);
	}
	cout << count << endl;
}

