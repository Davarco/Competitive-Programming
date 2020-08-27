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

int T, A, B, C;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> A >> C >> B;
		int a = A+1, b = B+1, c = C-1;
		if (C != 0 || A != 0)
			for (int i = 0; i < a; i++)
				cout << '0';
		if (C != 0 || B != 0)
			for (int i = 0; i < b; i++)
				cout << '1';
		int now = 0;
		for (int i = 0; i < c; i++)
			cout << char('0'+now), now = 1 - now;
		cout << endl;
	}
}

