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
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');

int T;
string S;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> S;
		int ans = INF;
		for (int a = 0; a <= 9; a++) for (int b = 0; b <= 9; b++)
		{
			int same = 0, first = true;
			for (int n = 0; n < S.size(); n++)
				if (first && S[n] - '0' == a)
					same++, first = false;
				else if (!first && S[n] - '0' == b)
					same++, first = true;
			if (a != b && same % 2 == 1)
				same--;
			ans = min(ans, (int)(S.size()) - same);
		}
		cout << ans << endl;
	}
}

