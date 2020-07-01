#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;
typedef vector<LL> vi;

int N;
vi denom({ 1, 5, 10, 25, 50 });
LL dp[30001];

int main()
{
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int d = 0; d < 5; d++)
		for (int c = denom[d]; c <= 30000; c++)
			dp[c] += dp[c-denom[d]];
	while (cin >> N)
	{
		LL M = dp[N];
		if (M == 1)
			printf("There is only %lld way to produce %d cents change.\n", M, N);
		else 
			printf("There are %lld ways to produce %d cents change.\n", M, N);
	}
}
