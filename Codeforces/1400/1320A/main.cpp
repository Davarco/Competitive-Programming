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
#define PLIST2(a, b) \
	for (int i = 0; i < b; i++) cout << a << (i == b-1 ? '\n' : ' ');

int N;

signed main()
{
	cin >> N;
	unordered_map<int, int> dp;
	for (int n = 1; n <= N; n++)
	{
		int B;
		cin >> B;
		dp[B-n] += B;
	}
	int best = 0;
	for (auto it = dp.begin(); it != dp.end(); it++)
		best = max(best, it->second);	
	cout << best << endl;
}

