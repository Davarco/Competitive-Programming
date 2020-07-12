#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <cstring>

using namespace std;

int N, X, T, K;
int prices[105];
int favors[105];
int dp[103][1005][23];

int maxfavor(int id, int spent, int count)
{
	int cost = spent+T*N;
	cost = ceil((double)cost*1.1L);
	if (cost > N*X || count > 2*N)
		return -100000000;
	if (cost == N*X || id < 0 || count == 2*N)
		return 0;
	if (dp[id][spent][count] == -1)
	{
		int a = maxfavor(id-1, spent, count);
		int b = favors[id] + maxfavor(id-1, spent+prices[id], count+1);
		int c = 2*favors[id] + maxfavor(id-1, spent+2*prices[id], count+2);
		dp[id][spent][count] = max(a, max(b, c));
	}
	return dp[id][spent][count];
}

int main()
{
	while (cin >> N >> X >> T >> K)
	{
		if (N == 0 && X == 0 && T == 0 && K == 0) break; N += 1;
		for (int k = 0; k < K; k++)
		{
			cin >> prices[k];
			int F = 0;
			for (int n = 0; n < N; n++)
			{
				int temp; cin >> temp;
				F += temp;
			}
			favors[k] = F;
		}
		memset(dp, -1, sizeof(dp));
		int favor = maxfavor(K-1, 0, 0);
		printf("%.2lf\n", (double)favor/(double)N);
	}
}
