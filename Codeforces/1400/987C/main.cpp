#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 1e15

int N;
int dp[3000][3][3001];
vi font, cost;

int brute(int i, int count, int prev)
{
	if (count == 3)
		return 0;
	if (i == N)
		return INF;
	if (dp[i][count][prev] != -1)
		return dp[i][count][prev];	
	int f = prev == 3000 ? 0 : font[prev]; 
	int a = font[i] > f ? cost[i] + brute(i+1, count+1, i) : INF;
	int b = brute(i+1, count, prev);
	int c = min(a, b);
	dp[i][count][prev] = c;
	return dp[i][count][prev];
}

signed main()
{
	cin >> N;
	font.assign(N, 0), cost.assign(N, 0);
	for (int n = 0; n < N; n++)
		cin >> font[n];
	for (int n = 0; n < N; n++)
		cin >> cost[n];

	memset(dp, -1, sizeof(dp));
	int best = brute(0, 0, 3000);
	if (best >= INF)
		cout << -1 << endl;
	else 
		cout << best << endl;
}

