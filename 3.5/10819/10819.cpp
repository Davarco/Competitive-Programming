#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int M, N, P, F;
vector<int> prices, favors;

int dp[120][12000];

int maxfavor(int item, int spent)
{
	/*
	 * Case 1: We can't reach the 200 bonus and we've overspent.
	 * Case 2: We've spent more than the 200 bonus.
	 * Case 3: We've reached the end, used the 200 bonus, but haven't spent enough for it.
	 */
	if ((spent > M && M <= 1800) || spent > M + 200 || (item == N && spent > M && spent <= 2000))
		return INT_MIN;
	if (item == N)
		return 0;
	if (dp[item][spent] == -1)
	{
		int a = maxfavor(item+1, spent);
		int b = favors[item] + maxfavor(item+1, spent+prices[item]);
		dp[item][spent] = max(a, b);
	}
	return dp[item][spent];
}

int main()
{
	while (cin >> M >> N)
	{
		prices.assign(N, 0); favors.assign(N, 0);
		for (int n = 0; n < N; n++) cin >> prices[n] >> favors[n];
		memset(dp, -1, sizeof(dp));
		int ans = maxfavor(0, 0);
		cout << ans << endl;
	}
}
