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

int T, X;
string S;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> S >> X;
		int N = S.size();	
		
		vi F(N, 1);
		for (int n = 0; n < N; n++)
			if (S[n] == '0')
			{
				if (n + X < N)
					F[n+X] = 0;
				if (n - X >= 0)
					F[n-X] = 0;
			}
		int found = false;
		for (int n = 0; n < N; n++)
		{
			if (S[n] == '1')
			{
				if (n + X < N && F[n+X] == 1)
					continue;
				if (n - X >= 0 && F[n-X] == 1)
					continue;

				found = true;
				break;
			}
		}
		if (found)
			cout << -1 << endl;
		else
		{
			for (int i = 0; i < N; i++)
				cout << F[i];
			cout << endl;
		}
	}
}

