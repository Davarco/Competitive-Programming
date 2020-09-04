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

int N, K;
string D[] = { 	"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", 
				"1101111", "1010010", "1111111", "1111011" };

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	vector<string> S(N);
	for (int n = 0; n < N; n++)
		cin >> S[n];
	reverse(S.begin(), S.end());

	int diff[N][10];
	memset(diff, 0, sizeof(diff));
	for (int n = 0; n < N; n++)
		for (int d = 0; d < 10; d++)
		{
			for (int i = 0; i < 7; i++)
				if (S[n][i] == '1' && D[d][i] == '0')
					diff[n][d] = -1;
				else if (diff[n][d] != -1 && S[n][i] != D[d][i])
					diff[n][d]++;
		}

	/*
	for (int n = 0; n < N; n++)
		PLIST(diff[n], 10);
	*/

	int dp[N][K+1];
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 10; i++)
	{
		int cost = diff[0][i];
		dp[0][cost] = i;
	}
	for (int n = 1; n < N; n++)
	{
		for (int k = 0; k <= K; k++)
		{
			for (int d = 0; d < 10; d++)
			{
				int cost = diff[n][d];
				if (cost != -1 && k - cost >= 0 && dp[n-1][k-cost] != -1)
					dp[n][k] = d;
			}
		}
	}
	/*
	for (int n = 0; n < N; n++)
		PLIST(dp[n], K+1);
	*/

	if (dp[N-1][K] == -1)
	{
		cout << -1 << endl;
		return 0;
	}
	int now = K, idx = N-1;
	queue<int> ans;
	while (idx >= 0)
	{
		ans.push(dp[idx][now]);	
		int cost = diff[idx][dp[idx][now]];
		now -= cost, idx--;
	}
	while (ans.size() > 0)
	{
		cout << ans.front();
		ans.pop();
	}
	cout << endl;
}

