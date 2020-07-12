#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

#define INF 1000000000

int T, P, N, M;
int denom[100];
int dp[20001];

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> P >> N; M = INF;
		for (int n = 0; n < N; n++) 
		{
			cin >> denom[n];
			M = min(M, denom[n]);
		}

		fill(dp, dp+20001, INF);
		dp[0] = 0;
		for (int c = 0; c < N; c++)
			for (int i = 20001-denom[c]-1; i >= 0; i--)
				if (dp[i] != INF)
					dp[i+denom[c]] = min(dp[i+denom[c]], dp[i]+1);
		for (int i = P; i <= 20001; i++)
			if (dp[i] != INF)
			{
				cout << i << " " << dp[i] << endl;
				break;
			}
	}
}
