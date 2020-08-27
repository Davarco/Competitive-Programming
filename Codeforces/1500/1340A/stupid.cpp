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

int T, N;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vi P(N);
		for (int n = 0; n < N; n++)
			cin >> P[n];
		vi I(N);
		for (int n = 0; n < N; n++)
			I[P[n]-1] = n;
		
		int end = N-1, next = -1, start = -1, found = true;
		for (int n = 0; n < N; n++)
		{
			if (next != -1)
			{
				if (next == end)
					end = start, next = -1;
				else if (I[n] == next)
					next++;
				else
				{
					found = false;
					goto end;
				}
			}
			else
			{
				if (I[n] == end)
					end--;
				else
					start = I[n]-1, next = I[n]+1;
			}
		}
end:
		if (found)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

