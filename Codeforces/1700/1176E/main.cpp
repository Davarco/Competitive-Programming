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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define endl '\n'
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int T, N, M;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		
		vi G[N];
		for (int m = 0; m < M; m++)
		{
			int u, v;
			cin >> u >> v, --u, --v;
			G[u].push_back(v), G[v].push_back(u);
		}

		vi dis(N, INF);
		queue<int> q;
		dis[0] = 0, q.push(0);
		while (q.size() > 0)
		{
			int u = q.front(); q.pop();
			for (int i = 0; i < G[u].size(); i++)
			{
				int v = G[u][i];
				if (dis[v] == INF)
					dis[v] = dis[u] + 1, q.push(v);
			}
		}

		vi A, B;
		for (int i = 0; i < N; i++)
			if (dis[i] % 2 == 0)
				A.push_back(i + 1);
			else
				B.push_back(i + 1);
		if (A.size() < B.size())
		{
			cout << A.size() << endl;
			PLIST(A, A.size());
		}
		else
		{
			cout << B.size() << endl;
			PLIST(B, B.size());
		}
	}
}

