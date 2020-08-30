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

int N, M, K;

signed main()
{
	cin >> N >> M >> K;
	vi A(N);
	vi B(M);
	for (int n = 0; n < N; n++)
		cin >> A[n];
	for (int m = 0; m < M; m++)
		cin >> B[m];
	sort(A.begin(), A.end()), sort(B.begin(), B.end());
	int m = 0, count = 0;
	for (int n = 0; n < N; n++)
	{
		while (m < M)
		{
			if (abs(A[n]-B[m]) <= K)
			{
				count++;
				m++;
				break;
			}
			if (B[m] - A[n] > K)
				break;
			m++;
		}
	}
	cout << count << endl;
}

