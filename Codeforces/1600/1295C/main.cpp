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
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int C;
string S, T;

signed main()
{
	cin >> C;
	for (int c = 0; c < C; c++)
	{
		cin >> S >> T;

		vi exi(26, false);
		for (int s = 0; s < S.size(); s++)
			exi[S[s]-'a'] = true;
		int found = false;
		for (int t = 0; t < T.size(); t++)
			if (!exi[T[t]-'a'])
				found = true;
		if (found)
		{
			cout << -1 << endl;
			continue;
		}

		vi pos[26];
		for (int s = 0; s < S.size(); s++)
			pos[S[s]-'a'].push_back(s);

		int count = 1, i = 0;
		for (int t = 0; t < T.size(); t++)
		{
			int L = T[t] - 'a';
			auto it = lower_bound(pos[L].begin(), pos[L].end(), i);
			if (it == pos[L].end())
				count++, i = 0, t--;
			else
				i = *it + 1;
		}
		cout << count << endl;
	}
}

