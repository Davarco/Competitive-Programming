#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int T, N;
vector<int> cars;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N; 
		cars.assign(N, 0); for (int n = 1; n <= N; n++) cin >> cars[n-1];
		if (N == 0) { cout << 0 << endl; continue; }

		vector<int> inc_dp(N, 1);
		for (int i = N-2; i >= 0; i--)
			for (int j = i+1; j < N; j++)
				if (cars[j] > cars[i] && inc_dp[j]+1 > inc_dp[i])
					inc_dp[i] = inc_dp[j] + 1;

		vector<int> dec_dp(N, 1); 
		for (int i = N-2; i >= 0; i--)
			for (int j = i+1; j < N; j++)
				if (cars[j] < cars[i] && dec_dp[j]+1 > dec_dp[i])
					dec_dp[i] = dec_dp[j] + 1;

		int ans = 0;
		for (int i = 0; i < N; i++)
			ans = max(ans, inc_dp[i]+dec_dp[i]-1);
		cout << ans << endl;
	}
}

