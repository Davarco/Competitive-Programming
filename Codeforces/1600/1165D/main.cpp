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

int T, N;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * (b / gcd(a, b));
}

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vi D(N);
		for (int n = 0; n < N; n++)
			cin >> D[n];
		sort(D.begin(), D.end());
		
		int X = D[0] * D[N-1];
		vi divisors;
		for (int i = 2; i*i <= X; i++)
		{
			if (X % i == 0)
				divisors.push_back(i);
			if (X % i == 0 && X != i*i)
				divisors.push_back(X / i);
		}
		sort(divisors.begin(), divisors.end());
		
		int found = false;
		if (divisors.size() != N)
			found = true;
		else
			for (int i = 0; i < N; i++)
				if (D[i] != divisors[i])
					found = true;
		if (!found)
			cout << X << endl;
		else
			cout << -1 << endl;
	}
}

