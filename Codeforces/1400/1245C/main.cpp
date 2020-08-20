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
string S;

signed main()
{
	cin >> S;
	N = S.size();
	for (int i = 0; i < N; i++)
		if (S[i] == 'm' || S[i] == 'w')
		{
			cout << 0 << endl;
			return 0;
		}

	vi dp(N+1);
	dp[0] = 1, dp[1] = 1;
	for (int i = 1; i < N; i++)
	{
		if (S[i] == S[i-1] && (S[i] == 'n' || S[i] == 'u'))
			dp[i+1] = (dp[i] + dp[i-1]) % MOD;
		else 
			dp[i+1] = dp[i] % MOD;
	}
	cout << dp[N] << endl;
}

