#include <bits/stdc++.h>
/*
 * Basic Runtimes Table:
 * +-----+-----------------+
 * |  n  | Worst Algorithm |
 * +-----+-----------------+
 * | 11  | O(n!), O(n^6)   |
 * | 18  | O(2^n * n^2)    |
 * | 22  | O(2^n * n)      |
 * | 100 | O(n^4)          |
 * | 400 | O(n^3)          |
 * | 2K  | O(n^2 log n)    |
 * | 10K | O(n^2)          |
 * | 1M  | O(n log n)      |
 * +-----+-----------------+
 *
 * Lower Bound: First >=, Upper Bound: First >
 */
using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int N, H, L, R;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> H >> L >> R;
	vi A(N);
	for (int n = 0; n < N; n++)
		cin >> A[n];

	vi dp(H);
	if (A[0] >= L && A[0] <= R)
		dp[A[0]]++;
	if (A[0]-1 >= L && A[0]-1 <= R)
		dp[A[0]-1]++;
	unordered_set<int> prev;
	prev.insert(A[0]), prev.insert(A[0]-1);
	for (int n = 1; n < N; n++)
	{
		vi temp;
		for (auto it = prev.begin(); it != prev.end(); it++)
		{
			int next = (A[n] + *it) % H;
			int next_count = dp[*it];
			if (next >= L && next <= R)
				next_count++;
			dp[next] = max(dp[next], next_count);
			temp.push_back(next);

			next = (A[n]-1 + *it) % H;
			next_count = dp[*it];
			if (next >= L && next <= R)
				next_count++;
			dp[next] = max(dp[next], next_count);
			temp.push_back(next);
		}
		prev.clear();
		for (int i = 0; i < temp.size(); i++)
			prev.insert(temp[i]);
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
}

