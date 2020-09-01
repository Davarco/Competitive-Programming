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
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int T, A, B, Q, L, R, N;

signed main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> A >> B >> Q;

		vi P(A*B+1);
		vi ans;
		for (int i = 1; i <= A*B; i++)
		{
			P[i] = P[i-1];
			if ((i % A) % B != (i % B) % A)
				P[i]++;
		}

		for (int q = 0; q < Q; q++)
		{
			cin >> L >> R;
			int cntL = (L-1) / (A*B), remL = (L-1) % (A*B);
			int cntR = R / (A*B), remR = R % (A*B);
			ans.push_back(P[A*B]*cntR + P[remR] - P[A*B]*cntL - P[remL]);
		}
		PLIST(ans, ans.size());
	}
}
