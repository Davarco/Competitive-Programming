#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;

int N, X, T, K, R, C;
vector<int> prices; vvi favors;
vvvi dp;

int maxfavor(int id, int spent, int count)
{
	int cost = round(1.1*(double)(spent+T*N));
	if (cost > C)
		return INT_MIN;
	if (id == R || count == 2*N)
		return 0;
	if (dp[id][spent][count] == -1)
	{
		int a = maxfavor(id+1, spent, count);
		int favor = 0; for (int i = 0; i < N; i++) favor += favors[id/2][i];
		int b = favor + maxfavor(id+1, spent+prices[id/2], count+1);
		dp[id][spent][count] = max(a, b);
	}
	return dp[id][spent][count];
}

int main()
{
	while (cin >> N >> X >> T >> K)
	{
		if (N == 0 && X == 0 && T == 0 && K == 0) break; N += 1;
		prices.assign(K, 0);
		favors.assign(K, vector<int>(N, 0));
		for (int k = 0; k < K; k++)
		{
			cin >> prices[k];
			for (int n = 0; n < N; n++) cin >> favors[k][n];
		}
		R = K*2; C = N*X;
		dp.assign(R, vvi(C, vector<int>(2*N, -1)));
		double favor = maxfavor(0, 0, 0);
		printf("%.02lf\n", favor/((double)(N)));
	}
}
