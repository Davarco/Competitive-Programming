#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long N, K, M;
long long dp[51][51][51];

int main()
{
	for (int n = 1; n <= 50; n++) for (int m = n; m <= 50; m++) dp[n][1][m] = 1;
	for (int n = 1; n <= 50; n++) dp[n][n][1] = 1;
	
	for (int n = 2; n <= 50; n++)
		for (int k = 2; k <= 50; k++)
			for (int m = 2; m <= 50; m++)
				if (n >= k && n <= k*m)
				{
					if (n-k+1 >= m)
						for (int i = 1; i <= m; i++)
							dp[n][k][m] += dp[n-i][k-1][m];
					else
						dp[n][k][m] = dp[n][k][m-1];
				}

	while (cin >> N >> K >> M)
		cout << dp[N][K][M] << endl;	
}
