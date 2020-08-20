#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define PLIST(a, b) \
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');

int T, N;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string S;
		cin >> N >> S;
		vi A(N);
		for (int n = 0; n < N; n++)
			A[n] = S[n] - '0';

		vi dp(N+1);
		dp[0] = 0;
		for (int n = 1; n <= N; n++)
			dp[n] = A[n-1] + dp[n-1];

		unordered_map<int, int> M;
		for (int n = 0; n <= N; n++)
			M[dp[n]-n]++;
		int count = 0;
		for (auto it = M.begin(); it != M.end(); it++)
			count += (it->second*(it->second-1))/2;
		cout << count << endl;
	}
}

