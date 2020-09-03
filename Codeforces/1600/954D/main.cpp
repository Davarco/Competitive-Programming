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

int N, M, S, T;
vi G[1000];

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> S >> T, --S, --T;
	int exists[N][N];
	memset(exists, 0, sizeof(exists));
	for (int m = 0; m < M; m++)
	{
		int a, b;
		cin >> a >> b, --a, --b;
		G[a].push_back(b), G[b].push_back(a), exists[a][b] = true, exists[b][a] = true;
	}

	queue<int> q;

	vi vis0(N, -1);
	q.push(S), vis0[S] = 0;
	while (q.size() > 0)
	{
		int u = q.front(); q.pop();
		for (int v: G[u])
			if (vis0[v] == -1)
				// q.push(ii(v, d+1)), pre[v] = u;
				vis0[v] = vis0[u] + 1, q.push(v);
	}

	vi vis1(N, -1);
	q.push(T), vis1[T] = 0;
	while (q.size() > 0)
	{
		int u = q.front(); q.pop();
		for (int v: G[u])
			if (vis1[v] == -1)
				// q.push(ii(v, d+1)), pre[v] = u;
				vis1[v] = vis1[u] + 1, q.push(v);
	}

	int best_dist = vis0[T], count = 0;
	for (int a = 0; a < N; a++)
		for (int b = 0; b < a; b++)
		{
			if (exists[a][b])
				continue;
			int cs0 = vis0[a] + vis1[b] + 1;
			int cs1 = vis1[a] + vis0[b] + 1;
			if (cs0 >= best_dist && cs1 >= best_dist)
				count++;
		}
	cout << count << endl;
}

