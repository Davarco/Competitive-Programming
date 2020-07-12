#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
#define INF 1000000000

int N, X;
int wind[10][1000];
int dp[10][1000];

int minfuel(int r, int c)
{
	if (c == X && r == 0)
		return 0;
	if (c == X && r != 0)
		return INF;
	if (dp[r][c] == -1)
	{
		int same = INF, up = INF, down = INF;
		same = 30 - wind[r][c] + minfuel(r, c+1);
		if (r != 9) up = 60 - wind[r][c] + minfuel(r+1, c+1);
		if (r != 0) down = 20 - wind[r][c] + minfuel(r-1, c+1);
		dp[r][c] = min({ same, up, down });
	}
	return dp[r][c];
}

int main()
{
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		cin >> X; X /= 100;
		for (int r = 9; r >= 0; r--) for (int c = 0; c < X; c++) cin >> wind[r][c];
		memset(dp, -1, sizeof(dp));
		int ans = minfuel(0, 0);

		cout << ans << endl << endl;
	}
}
