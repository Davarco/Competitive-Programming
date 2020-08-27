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
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int T, L, R, M;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> L >> R >> M;

		int N = -1, A = L, B, C;
		int a = M - R + L, b = M + R - L;
		for (int i = a; i <= b; i++)
			if (i % L == 0)
			{
				N = i / L;
				if (i <= M)
					B = i + L, C = L;
				else
					C = i + L, B = L;
			}

		cout << A << " " << B << " " << C << endl;
	}
}


