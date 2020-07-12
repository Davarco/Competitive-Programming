#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;
#define INF 1000000000

int N, M, S;
int X[40], Y[40];
int dp[301][301];

int main()
{
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		cin >> M >> S;
		for (int m = 0; m < M; m++) cin >> X[m] >> Y[m];

		memset(dp, INF, sizeof(dp));
		dp[0][0] = 0;
		for (int r = 0; r <= S; r++) for (int c = 0; c <= S; c++)
		{
			if (r == 0 && c == 0) continue;
			int best = INF;
			for (int m = 0; m < M; m++)
			{
				int a = r-X[m], b = c-Y[m];
				if (a >= 0 && b >= 0 && dp[a][b]+1 < best) best = dp[a][b]+1;
			}
			dp[r][c] = best;
		}
		int best = INF;
		for (int r = 0; r <= S; r++) for (int c = 0; c <= S; c++)
			if (r*r + c*c == S*S && dp[r][c] < best)
				best = dp[r][c];

		if (best == INF) 
			cout << "not possible" << endl;
		else 
			cout << best << endl;
	}
}
