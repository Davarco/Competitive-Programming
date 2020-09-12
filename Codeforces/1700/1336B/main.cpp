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
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define endl '\n'
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int T, NR, NG, NB;

int compute(vector<int> &A, vector<int> &B, vector<int> &C)
{
	int best = LLONG_MAX;
	for (int n = 0; n < A.size(); n++)
	{
		int cb = upper_bound(B.begin(), B.end(), A[n]) - B.begin();
		if (cb == 0 || B[cb-1] > A[n])
			continue;
		else
			cb--;
		int cc = lower_bound(C.begin(), C.end(), A[n]) - C.begin();
		if (cc == C.size() || C[cc] < A[n])
			continue;
		int a = A[n] - B[cb], b = A[n] - C[cc], c = B[cb] - C[cc];
		int sum = a*a + b*b + c*c;
		best = min(best, sum);
	}
	return best;
}

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> NR >> NG >> NB;
		vi R(NR);
		vi G(NG);
		vi B(NB);
		for (int n = 0; n < NR; n++)
			cin >> R[n];
		for (int n = 0; n < NG; n++)
			cin >> G[n];
		for (int n = 0; n < NB; n++)
			cin >> B[n];
		sort(R.begin(), R.end()), sort(G.begin(), G.end()), sort(B.begin(), B.end());

		int a = compute(R, G, B), b = compute(R, B, G), c = compute(G, R, B);
		int d = compute(G, B, R), e = compute(B, R, G), f = compute(B, G, R);
		cout << min({ a, b, c, d, e, f }) << endl;
	}
}

