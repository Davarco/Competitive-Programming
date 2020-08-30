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
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int N, K;
vi G[200000], used, ancs, chdr;

int dfs(int u, int n)
{
	if (used[u])
		return 0;
	used[u] = true, ancs[u] = n;
	int sum = 1;
	for (int i = 0; i < G[u].size(); i++)
		if (!used[G[u][i]])
			sum += dfs(G[u][i], n+1);
	chdr[u] = sum - 1;
	return sum;
}

signed main()
{
	cin >> N >> K;
	for (int n = 0; n < N-1; n++)
	{
		int a, b;
		cin >> a >> b, a--, b--;
		G[a].push_back(b), G[b].push_back(a);
	}

	used.assign(N, false), ancs.assign(N, 0), chdr.assign(N, 0);
	dfs(0, 0);
	vii cities;
	for (int n = 0; n < N; n++)
		cities.push_back(ii(ancs[n] - chdr[n], n));
	sort(cities.begin(), cities.end(), greater<ii>());
	int ans = 0;
	for (int k = 0; k < K; k++)
		ans += cities[k].first;
	cout << ans << endl;
}

