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
#define endl '\n'
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int K;

signed main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> K;
	if (K == 0)
		cout << "1 1" << endl << 1 << endl;
	else
	{
		int X = 1, N = 1;
		while (X <= K)
			X *= 2, N++;
		
		int a = (1 << N) - 1;
		int b = (1 << (N - 1));
		cout << "3 3" << endl;
		cout << a << " " << K << " " << 0 << endl;
		cout << b << " " << K << " " << 0 << endl;
		cout << b << " " << a << " " << K << endl;
	}
}

