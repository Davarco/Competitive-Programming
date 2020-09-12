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

int N, M, K, T;
vi G[200001], F[200001], P;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int m = 0; m < M; m++)
	{
		int u, v;
		cin >> u >> v;
		G[v].push_back(u), F[u].push_back(v);
	}
	cin >> K;
	P.assign(K, 0);
	for (int k = 0; k < K; k++)
		cin >> P[k];

	T = P[K-1];
	vi dis(N+1, -1);
	queue<int> q;
	dis[T] = 0, q.push(T);
	while (q.size() > 0)
	{
		int u = q.front(); q.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (dis[v] == -1)
				q.push(v), dis[v] = dis[u] + 1;
		}
	}

	int minimum = 0, extra = 0;
	for (int k = 0; k < K-1; k++)
	{
		int a = P[k], b = P[k+1];
		minimum += (dis[b] > dis[a] - 1);
		for (int i = 0; i < F[a].size(); i++)
		{
			int v = F[a][i];
			if (v != b && dis[v] == dis[a] - 1)
			{
				extra++;
				break;
			}
		}
	}
	cout << minimum << " " << extra << endl;
}

