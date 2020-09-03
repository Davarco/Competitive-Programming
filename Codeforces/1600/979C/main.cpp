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
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int N, F, B;
vi G[300000], vis, size, contains_f;

int dfs(int u)
{
	vis[u] = true;
	if (u == F)
		contains_f[u] = true;
	for (int i = 0; i < G[u].size(); i++)
		if (!vis[G[u][i]])
			size[u] += dfs(G[u][i]), contains_f[u] = contains_f[u] || contains_f[G[u][i]];
	return ++size[u];
}

signed main()
{
	scanf("%lld %lld %lld\n", &N, &F, &B), --F, --B;
	for (int n = 0; n < N-1; n++)
	{
		int a, b;
		scanf("%lld %lld\n", &a, &b), --a, --b;
		G[a].push_back(b), G[b].push_back(a);
	}

	vis.assign(N, 0), size.assign(N, 0), contains_f.assign(N, 0);
	dfs(B);
	
	int a = size[F], b = 1;
	for (int i = 0; i < G[B].size(); i++)
		if (!contains_f[G[B][i]])
			b += size[G[B][i]];
	cout << N*(N-1) - a*b << endl;
}

