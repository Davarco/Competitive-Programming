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

		dp[0] = 0;
		for (int a = 1; a <= P+M; a++)
		{
			dp[a] = INF;
			for (int b = 0; b < N; b++)
				if (a-denom[b] >= 0)
					dp[a] = min(dp[a], dp[a-denom[b]]+1);
		}
		for (int a = P; a <= P+M; a++)
			if (dp[a] < INF)
			{
				cout << a << " " << dp[a] << endl;
				break;
			}
	}
}
