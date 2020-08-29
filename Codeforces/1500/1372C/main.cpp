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

int T, N;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vi A(N);
		for (int n = 0; n < N; n++)
			cin >> A[n];

		int a = 0, b = N-1;
		while (a < b && A[a] == a+1)
			a++;
		while (b > a && A[b] == b+1)
			b--;

		if (a < b)
		{
			int change = 1;
			for (int i = a; i <= b; i++)
				if (A[i] == i+1)
					change = 2;
			cout << change << endl;
		}
		else
			cout << 0 << endl;
	}
}

