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
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int N;

signed main()
{
	cin >> N;	
	int G[N+2][N+2];
	memset(G, 0, sizeof(G));
	for (int n = 1; n <= N; n++)
		G[n][n] = 1, G[n-1][n] = 1, G[n+1][n] = 1, G[n][n-1] = 1, G[n][n+1] = 1;
	G[0][0] = 1, G[N+1][N+1] = 1;
	vii res;
	for (int a = 0; a < N+2; a++)
		for (int b = 0; b < N+2; b++)
			if (G[a][b])
				res.push_back(ii(a, b));
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i].first << " " << res[i].second << endl;
}

