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

int N, K;

signed main()
{
	cin >> N >> K;
	vi both, A, B;
	for (int n = 0; n < N; n++)
	{
		int t, a, b;
		cin >> t >> a >> b;
		if (a + b == 2)
			both.push_back(t);
		else if (a == 1)
			A.push_back(t);
		else if (b == 1)
			B.push_back(t);
	}
	if (both.size() + min(A.size(), B.size()) < K)
	{
		cout << -1 << endl;
		return 0;
	}
	sort(both.begin(), both.end(), greater<int>());
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), greater<int>());
	int reading = 0;
	while (K != 0)
	{
		if (A.size() == 0 || B.size() == 0)
			reading += both.back(), both.pop_back(), K--;
		else if (both.size() == 0)
			reading += A.back(), reading += B.back(), A.pop_back(), B.pop_back(), K--;
		else
		{
			if (A.back() + B.back() < both.back())
				reading += A.back(), reading += B.back(), A.pop_back(), B.pop_back(), K--;
			else
				reading += both.back(), both.pop_back(), K--;
		}
	}
	cout << reading << endl;
}

