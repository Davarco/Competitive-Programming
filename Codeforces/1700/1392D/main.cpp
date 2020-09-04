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

int T, N;
string S;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> S;
		// RL RRL RLL RRLL
		bool same = true;
		for (int n = 0; n < N; n++)
			if (S[n] != S[0])
				same = false;
		if (same)
		{
			cout << (N+2)/3 << endl;
		}
		else
		{
			int start = 0;
			while (start != N && S[++start] == S[0]);

			int count = 0, ans = 0;
			char now = S[start];
			for (int n = 0; n < N; n++)
			{
				int idx = (start+n) % N;
				if (S[idx] == now)
					count++;
				else
					now = S[idx], ans += count/3, count = 1;
			}
			ans += count/3;
			cout << ans << endl;
		}
	}
}

