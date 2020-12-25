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

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define endl '\n'
#define plist(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

#define int ll

int N;
string S;

signed main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> S, N = S.size();
	int tens = 1;

	vi dp(N);
	dp[0] = 0, tens = 1;
	for (int n = 1; n < N; n++)
		dp[n] = (dp[n-1] + tens*n) % MOD, tens = (tens * 10) % MOD;

	int ans = 0; tens = 1;
	for (int n = 0; n < N; n++)
	{
		int i = N-1-n, d = S[i] - '0', a = i, b = N-i-1;
		int t0 = (a*(a+1)/2) % MOD;
		int t1 = (d*tens) % MOD;
		int t2 = (t0*t1 + d*dp[b]) % MOD;
		ans = (ans + t2) % MOD;
		tens = (tens * 10) % MOD;
	}
	cout << ans << endl;
}

