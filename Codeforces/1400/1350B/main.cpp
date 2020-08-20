#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define PLIST(a, b) \
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');
#define PLIST2(a, b) \
	for (int i = 0; i < b; i++) cout << a << (i == b-1 ? '\n' : ' ');

int T, N;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vi S(N);
		for (int n = 0; n < N; n++)
			cin >> S[n];
		
		vi dp(N, 1);
		for (int a = 0; a < N; a++)
			for (int b = a; b < N; b += (a+1))
				if (S[a] < S[b])
					dp[b] = max(dp[b], dp[a]+1);
		cout << *max_element(dp.begin(), dp.end()) << endl;
	}
}

