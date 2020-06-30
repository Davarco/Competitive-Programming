#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int T, N;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vector<int> heights(N), widths(N);
		for (int n = 0; n < N; n++) cin >> heights[n];
		for (int n = 0; n < N; n++) cin >> widths[n];

		vector<int> inc_dp(N); inc_dp[0] = widths[0];
		for (int i = 1; i < N; i++)
		{
			inc_dp[i] = widths[i];
			for (int j = 0; j < i; j++)
				if (heights[i] > heights[j] && inc_dp[j] + widths[i] > inc_dp[i])
					inc_dp[i] = inc_dp[j] + widths[i];
		}
		int max_inc_seq = *max_element(inc_dp.begin(), inc_dp.end());

		vector<int> dec_dp(N); dec_dp[0] = widths[0];
		for (int i = 1; i < N; i++)
		{
			dec_dp[i] = widths[i];
			for (int j = 0; j < i; j++)
				if (heights[i] < heights[j] && dec_dp[j] + widths[i] > dec_dp[i])
					dec_dp[i] = dec_dp[j] + widths[i];
		}
		int max_dec_seq = *max_element(dec_dp.begin(), dec_dp.end());

		if (max_inc_seq >= max_dec_seq)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", t+1, max_inc_seq, max_dec_seq);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", t+1, max_dec_seq, max_inc_seq);
	}
}
