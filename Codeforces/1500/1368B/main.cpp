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
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');

int K;

signed main()
{
	cin >> K;
	int count = 1;
	vi freq(10, 1);

	int i = 0;
	while (count < K)
	{
		count /= freq[i];
		count *= ++freq[i];
		i = (i + 1) % 10;
	}
	
	string S = "codeforces";
	for (int i = 0; i < 10; i++)
		for (int n = 0; n < freq[i]; n++)
			cout << S[i];
	cout << endl;
}

