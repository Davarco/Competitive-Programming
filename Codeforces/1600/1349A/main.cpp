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

int N, L;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;
	vi A(N);
	for (int n = 0; n < N; n++)
		cin >> A[n];

	vi pre(N);
	vi suf(N);
	pre[0] = A[0], suf[0] = A[N-1];
	for (int n = 1; n < N; n++)
		pre[n] = gcd(A[n], pre[n-1]), suf[n] = gcd(A[N-n-1], suf[n-1]);

	vi divisors(N);
	for (int n = 0; n < N; n++)
	{
		if (n == 0)
			divisors[n] = suf[N-2];
		else if (n == N-1)
			divisors[n] = pre[N-2];
		else
			divisors[n] = gcd(pre[n-1], suf[N-n-2]);
	}

	int prev = divisors[0];
	for (int n = 1; n < N; n++)
		prev = divisors[n] * prev / gcd(divisors[n], prev);
	cout << prev << endl;
}

