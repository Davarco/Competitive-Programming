#include <bits/stdc++.h>

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
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');
#define PLIST2(a, b) \
	for (int i = 0; i < b; i++) cout << a << (i == b-1 ? '\n' : ' ');

int N;

signed main()
{
	cin >> N;
	vi dp(N+1, 0);
	dp[0] = 1;
	for (int n = 1; n <= N; n++)
		for (int d = 1; d <= 6; d++)
			if (n-d >= 0)
				dp[n] = (dp[n] + dp[n-d]) % MOD;
	cout << dp[N] << endl;
}

