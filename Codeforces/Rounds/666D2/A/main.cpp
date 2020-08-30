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

signed main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vector<string> S(N);
		for (int n = 0; n < N; n++)
			cin >> S[n];

		vi count(26);
		for (int n = 0; n < N; n++)
			for (int i = 0; i < S[n].size(); i++)
				count[S[n][i]-'a']++;

		int found = true;
		for (int i = 0; i < 26; i++)
			if (count[i] % N != 0)
				found = false;
		if (found)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

