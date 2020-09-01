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

int N, M;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vi candies(M);
	for (int m = 1; m <= M; m++)
		candies[(m*m) % M] += N / M + (m <= (N % M));
	int ans = 0;
	for (int m = 1; m <= M/2; m++)
		if (M != m*2)
			ans += candies[m] * candies[M-m] * 2;
		else
			ans += candies[m] * candies[m];
	ans += candies[0] * candies[0];
	cout << ans << endl;
}

