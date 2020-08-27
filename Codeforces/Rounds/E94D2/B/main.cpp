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

int T, P, F, NS, NW, S, W;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> P >> F >> NS >> NW >> S >> W;
		if (F > P)
			swap(F, P);
		if (S > W)
			swap(NS, NW), swap(S, W);
		int best = 0;
		for (int w = 0; w <= NW; w++)
		{
			if (w*W > P)
				continue;
			int a = P, b = F, c = NS, d = NW, count = 0;
			int p, q;
			
			d -= w, count += w, a -= w*W;
			q = min(a/S, c);
			c -= q, count += q, a -= q*S;

			p = min(b/S, c);
			c -= p, count += p, b -= p*S;
			q = min(b/W, d);
			d -= q, count += q, b -= q*W;
			best = max(best, count);
		}
		cout << best << endl;
	}
}

