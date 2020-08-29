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

int N, M;

signed main()
{
	cin >> N >> M;
	vi A(N);
	vi B(M);
	for (int n = 0; n < N; n++)
		cin >> A[n];
	for (int m = 0; m < M; m++)
		cin >> B[m];

	for (int i = 0; i < (1 << 9); i++)
	{
		int works = true;
		for (int a = 0; a < N; a++)
		{
			int found = false;
			for (int b = 0; b < M; b++)
				if (((A[a] & B[b]) | i) == i)
					found = true;
			if (!found)
				works = false;
		}

		if (works)
		{
			cout << i << endl;
			break;
		}
	}
}

