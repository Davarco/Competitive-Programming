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
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define PLIST(a, b) \
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');

int N;
vi seq, vis, res;
vvi G;

void dfs(int u)
{
	vis[u] = true;
	for (int i = 0; i < G[u].size(); i++)
		if (!vis[G[u][i]])
			dfs(G[u][i]);
	res.push_back(u);
}

signed main()
{
	cin >> N;
	seq.assign(N, 0);
	G.assign(N, vi());
	for (int n = 0; n < N; n++)
		cin >> seq[n];
	for (int a = 0; a < N; a++)
		for (int b = 0; b < a; b++)
			if (seq[a] / 3 == seq[b] && seq[a] % 3 == 0)
				G[a].push_back(b);
			else if (seq[a] * 2 == seq[b])
				G[a].push_back(b);
			else if (seq[b] / 3 == seq[a] && seq[b] % 3 == 0)
				G[b].push_back(a);
			else if (seq[b] * 2 == seq[a])
				G[b].push_back(a);

	vis.assign(N, false);
	for (int n = 0; n < N; n++)
		if (!vis[n])
			dfs(n);
	reverse(res.begin(), res.end());
	for (int n = 0; n < res.size(); n++)
		cout << seq[res[n]] << (n == res.size()-1 ? '\n' : ' ');
}

