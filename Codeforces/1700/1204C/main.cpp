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

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;
	vector<string> temp(N);
	for (int n = 0; n < N; n++)
		cin >> temp[n];

	cin >> M;
	vi S(M);
	for (int m = 0; m < M; m++)
		cin >> S[m], --S[m];

	int G[N][N];
	for (int a = 0; a < N; a++) for (int b = 0; b < N; b++)
		if (a == b)
			G[a][b] = 0;
		else if (temp[a][b] == '1')
			G[a][b] = 1;
		else
			G[a][b] = INF;
	for (int n = 0; n < N; n++)
		for (int a = 0; a < N; a++) for (int b = 0; b < N; b++)
			G[a][b] = min(G[a][b], G[a][n] + G[n][b]);

	vi ans;
	ans.push_back(0);
	for (int m = 1; m < M; m++)
		if (G[S[ans.back()]][S[m]] != m - ans.back())
			ans.push_back(m-1);
	ans.push_back(M-1);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ++S[ans[i]] << (i == ans.size()-1 ? '\n' : ' ');
}

