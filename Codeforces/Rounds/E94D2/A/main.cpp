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
string S;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> S;
		int count[N];
		memset(count, -1, sizeof(count));
		for (int a = 0; a < N; a++)
		{
			for (int b = 0; b < N; b++)
			{
				int c = S[a+b] - '0';
				if (count[b] == -1)
					count[b] = c;
				else if (count[b] != c)
					count[b] = 2;
			}
		}
		for (int i = 0; i < N; i++)
			if (count[i] == 0 || count[i] == 1)
				cout << count[i];
			else
				cout << 0;
		cout << endl;
	}
}

