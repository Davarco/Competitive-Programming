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

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define endl '\n'
#define plist(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int T, N;
vvi edges; vi cnt, cen, vis;

int dfs(int u)
{
	if (vis[u])
		return 0;
	else
	{
		vis[u] = true;
		cnt[u] = 1;
		for (int v: edges[u])
			cnt[u] += dfs(v);
		return cnt[u];
	}
}

int leaf(int u)
{
	if (vis[u])
		return -1;
	else
	{
		vis[u] = true;
		if (cnt[u] != 1)
			for (int v: edges[u])
			{
				int l = leaf(v);
				if (l != -1)
					return l;
			}
		else
			return u;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cin >> N;
		edges.assign(N, vi()), cnt.assign(N, 0), cen.assign(N, 0);
		ii simple;
		for (int n = 0; n < N-1; ++n)
		{
			int a, b;
			cin >> a >> b, --a, --b;
			edges[a].push_back(b), edges[b].push_back(a);
			simple = ii(a, b);
		}
		
		vis.assign(N, false);
		dfs(0);
		for (int u = 0; u < N; u++)
		{
			vi temp = { N - cnt[u] };
			for (int v: edges[u])
				if (cnt[v] < cnt[u])
					temp.push_back(cnt[v]);
			cen[u] = *max_element(temp.begin(), temp.end());
		}
		// plist(cnt, cnt.size());
		// plist(cen, cen.size());

		vi centroids;
		int best = *min_element(cen.begin(), cen.end());
		for (int u = 0; u < N; u++)
			if (cen[u] == best)
				centroids.push_back(u);
		if (centroids.size() == 1)
		{
			cout << simple.first+1 << " " << simple.second+1 << endl;
			cout << simple.first+1 << " " << simple.second+1 << endl;
		}
		else
		{
			int a = centroids[0], b = centroids[1];
			vis.assign(N, false);
			if (cnt[a] < cnt[b])
			{
				vis[b] = true;
				int l = leaf(a);
				cout << l+1 << " " << edges[l][0]+1 << endl;
				cout << l+1 << " " << b+1 << endl;
			}
			else
			{
				vis[a] = true;
				int l = leaf(b);
				cout << l+1 << " " << edges[l][0]+1 << endl;
				cout << l+1 << " " << a+1 << endl;
			}
		}
	}
}

