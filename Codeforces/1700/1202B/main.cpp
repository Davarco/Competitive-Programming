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

vi S;

signed main()
{
	int n;
	while (scanf("%1d", &n) != EOF)
		S.push_back(n);

	int dp[10][10][10];
	memset(dp, 0, sizeof(dp));
	for (int a = 0; a < 10; a++) for (int b = 0; b < 10; b++)
		for (int d = 0; d < 10; d++)
		{
			int best = INF;
			for (int i = 0; i <= 10; i++) for (int j = 0; j <= 10; j++)
				if ((i != 0 || j != 0) && (a*i + b*j) % 10 == d)
					best = min(best, i+j);	
			dp[a][b][d] = best;
		}
	for (int a = 0; a < 10; a++) for (int b = 0; b < 10; b++)
	{
		int total = 0;
		for (int i = 0; i < S.size()-1; i++)
		{
			int d = (S[i+1] - S[i] < 0 ? S[i+1] - S[i] + 10 : S[i+1] - S[i]);
			if (dp[a][b][d] == INF)
				total = INF;
			else
				total += dp[a][b][d] - 1;
		}
		cout << (total >= INF ? -1 : total) << ' '; 
		if (b == 9)
			cout << endl;
	}
}

