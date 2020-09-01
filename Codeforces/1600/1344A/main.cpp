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
		vi A(N);
		for (int n = 0; n < N; n++)
			cin >> A[n];

		vi B(N);
		for (int n = 0; n < N; n++)
			B[n] = (A[n] + n) % N, B[n] = (B[n] < 0 ? B[n] + N : B[n]);
		sort(B.begin(), B.end());
		int found = false;
		for (int i = 0; i < B.size()-1; i++)
			if (B[i] == B[i+1])
				found = true;
		cout << (found ? "NO" : "YES") << endl;
	}
}

