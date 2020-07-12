#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int LL;

int N, K;
LL dp[101][101];

int main()
{
	while (cin >> N >> K)
	{
		if (N == 0 && K == 0) break;
		memset(dp, 0, sizeof(dp));
		for (int n = 0; n <= N; n++) 
		{
			dp[n][0] = 0;
			dp[n][1] = 1;
		}
		for (int k = 2; k <= K; k++)
		{
			for (int a = 0; a <= N; a++) for (int b = 0; b <= a; b++)
			{
				dp[a][k] += dp[a-b][k-1];
				dp[a][k] = dp[a][k] % 1000000;
			}
		}
		LL ans = dp[N][K] % 1000000;
		if (ans < 0) ans += 1000000;
		cout << ans << endl;
	}
}
