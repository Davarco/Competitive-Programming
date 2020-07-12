#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <cstring>
#include <bitset>

using namespace std;
#define INF 100000000

int T, N, END;
int X[11], Y[11];
int dp[11][2048];

int tsp(int pos, int mask)
{
	if (mask == END)
		return abs(X[pos]-X[0]) + abs(Y[pos]-Y[0]);
	if (dp[pos][mask] == -1)
	{
		dp[pos][mask] = INF;
		for (int n = 0; n < N; n++)
		{
			if ((mask & (1 << n)) == 0) 
			{
				int next = abs(X[pos]-X[n]) + abs(Y[pos]-Y[n]) + tsp(n, mask | (1 << n));
				dp[pos][mask] = min(dp[pos][mask], next);
			}
		}
	}
	return dp[pos][mask];
}

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> X[0] >> Y[0]; // Ignore, not needed.
		cin >> X[0] >> Y[0];
		cin >> N;
		for (int n = 1; n <= N; n++) cin >> X[n] >> Y[n]; N += 1;
		END = 1; for (int n = 0; n < N; n++) END *= 2; END -= 1;

		for (int a = 0; a < 11; a++) for (int b = 0; b < 2048; b++) dp[a][b] = -1;
		int ans = tsp(0, 1);
		printf("The shortest path has length %d\n", ans);
	}
}
