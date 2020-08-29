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

int N;

signed main()
{
	cin >> N;
	unordered_set<int> us;
	vi A(N);
	for (int n = 0; n < N; n++)
		cin >> A[n], us.insert(A[n]);

	vi B(N, -1);
	for (int n = 0; n < N-1; n++)
		if (A[n] != A[n+1])
			B[n+1] = A[n];

	int v = 0;
	for (int i = 0; i < N; i++)
	{
		if (B[i] == -1)
		{
			while (us.count(v) > 0)
				v++;
			B[i] = v++;
		}
	}
	PLIST(B, N);
}

