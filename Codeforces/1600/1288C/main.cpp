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

/*
 * This is a math question, so I think the best thing to do is to write down the process. 
 *
 * First, we note that if we rearrange the A+B sequence into A1...AM, BM...B1, this forms a
 * non-decreasing sequence. This is because A1..AM and BM..B1 are both non-decreasing and BM > AM
 * from the question statement. Then, our question becomes the number of ways we can choose 2M
 * numbers from 1..N with repetition.
 *
 * This becomes stars-and-bars. The answer is (N+2M-1) C (2M).
 */

int N, M;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	
	int A = N+2*M;
	int dp[A][A];
	dp[0][0] = 1;
	for (int a = 1; a < A; a++)
	{
		dp[a][0] = 1, dp[a][a] = 1;
		for (int b = 1; b < a; b++)
			dp[a][b] = (dp[a-1][b-1] + dp[a-1][b]) % MOD;
	}
	cout << dp[A-1][2*M] << endl;
}

