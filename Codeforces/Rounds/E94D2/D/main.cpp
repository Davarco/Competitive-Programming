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

int T, N;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vi A(N);
		for (int n = 0; n < N; n++)
			cin >> A[n], A[n]--;
		
		vvi dp(N, vi(N));
		for (int n = 0; n < N; n++)
		{
			int count = 0;
			for (int i = N-1; i >= 0; i--)
			{
				dp[n][i] = count;
				if (A[i] == n)
					count++;
			}
		}

		vi id[N];
		for (int i = 0; i < N; i++)
			id[A[i]].push_back(i);

		int count = 0;
		for (int a = 0; a < N; a++)
		{
			if (id[a].size() >= 4)
			{
				int comb = 1;
				for (int i = max(4, int(id[a].size())-4)+1; i <= id[a].size(); i++)
					comb *= i;
				for (int i = 1; i <= min(4, int(id[a].size())-4); i++)
					comb /= i;
				count += comb;
			}
			int prev = 0;
			for (int i = 0; i < id[a].size(); i++)
				for (int j = 0; j < i; j++)
					for (int k = id[a][j]+1; k < id[a][i]; k++)
						if (A[k] != a && id[a][i]+1 < N)
							count += dp[A[k]][id[a][i]+1];
		}
		cout << count << endl;
	}
}

