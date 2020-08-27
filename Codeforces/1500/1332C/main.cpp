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

int T, N, K;
string S;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K >> S;
		int count[(K+1)/2][26];
		memset(count, 0, sizeof(count));
		for (int n = 0; n < N; n += K)
			for (int k = 0; k < (K+1)/2; k++)
				count[k][S[n+k]-'a']++, count[k][S[n+K-k-1]-'a']++;
		int period[(K+1)/2];
		memset(period, 0, sizeof(period));
		for (int k = 0; k < (K+1)/2; k++)
			for (int i = 0; i < 26; i++)
				if (count[k][i] > count[k][period[k]])
					period[k] = i;


		int change = 0;
		for (int n = 0; n < N; n += K)
		{
			for (int k = 0; k < (K+1)/2; k++)
			{
				if (period[k] != (S[n+k] - 'a'))
					change++;
				if (period[k] != (S[n+K-k-1] - 'a'))
					change++;
			}
			if (K % 2 == 1)
				if (period[K/2] != (S[n+K/2] - 'a'))
					change--;
		}
		/*
		for (int n = 0; n < N; n += K)
			for (int k = 0; k < K; k++)
				cout << char(period[k] + 'a'); cout << endl;
		*/

		cout << change << endl;
	}
}

