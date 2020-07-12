#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int M, N, P, F;
vector<int> prices, favors;

int dp[100][12000][2];

int maxfavor(int item, int spent, int refund, int remaining)
{
	if (refund == 0 && spent >= 2000) 
	{
		remaining += 200;
		refund = 1;
	}
	if (item == N || remaining <= 0) 
		return 0;
	if (dp[item][remaining][refund] == -1)
	{
		/*
		if ((refund || spent+remaining < 2000) && prices[item] > remaining) 
			dp[item][remaining][refund] = maxfavor(item+1, spent, refund, remaining);
		else if (!refund && prices[item] > remaining+200 && spent+remaining >= 2000)
			dp[item][remaining][refund] = maxfavor(item+1, spent, refund, remaining);
		*/
		if (prices[item] > remaining) 
			dp[item][remaining][refund] = maxfavor(item+1, spent, refund, remaining);
		else 
		{
			int a = maxfavor(item+1, spent, refund, remaining);
			int b = favors[item] + maxfavor(item+1, spent+prices[item], refund, remaining-prices[item]);
			dp[item][remaining][refund] = max(a, b);
		}
	}
	return dp[item][remaining][refund];
}

int main()
{
	while (cin >> M >> N)
	{
		prices.assign(N, 0); favors.assign(N, 0);
		for (int n = 0; n < N; n++) cin >> prices[n] >> favors[n];
		memset(dp, -1, sizeof(dp));
		int ans = maxfavor(0, 0, 0, M);
		cout << ans << endl;
	}
}
