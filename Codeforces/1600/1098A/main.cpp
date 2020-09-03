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

int N, P[200001], S[200001], ans;
vi G[200001];

void dfs0(int u, int pre, int depth)
{
	if (depth % 2 == 1)
		for (int i = 0; i < G[u].size(); i++)
			dfs0(G[u][i], u, depth+1);
	else
	{
		if (G[u].size() == 0)
			S[u] = S[pre];
		else
		{
			S[u] = LLONG_MAX;
			for (int i = 0; i < G[u].size(); i++)
				dfs0(G[u][i], u, depth+1), S[u] = min(S[u], S[G[u][i]]);
		}
	}
}

void dfs1(int u, int pre)
{
	if (S[u] < S[pre])
	{
		cout << -1 << endl;
		exit(0);
	}
	else
	{
		ans += S[u] - S[pre];
		for (int i = 0; i < G[u].size(); i++)
			dfs1(G[u][i], u);
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int n = 2; n <= N; n++)
		cin >> P[n], G[P[n]].push_back(n);
	for (int n = 1; n <= N; n++)
		cin >> S[n];
	dfs0(1, 0, 1);
	ans = 0;
	dfs1(1, 0);
	cout << ans << endl;
}

