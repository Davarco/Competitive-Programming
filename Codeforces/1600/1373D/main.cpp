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
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int T, N;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vi A(N);
		for (int n = 0; n < N; n++)
			cin >> A[n];
		vi B, C;
		for (int n = 0; n < N-1; n += 2)
			B.push_back(A[n+1] - A[n]);
		for (int n = 1; n < N-1; n += 2)
			C.push_back(A[n] - A[n+1]);
		
		int nowB = 0, ansB = 0;
		for (int i = 0; i < B.size(); i++)
		{
			nowB += B[i];
			ansB = max(ansB, nowB);
			if (nowB < 0) nowB = 0;
		}

		int nowC = 0, ansC = 0;
		for (int i = 0; i < C.size(); i++)
		{
			nowC += C[i];
			ansC = max(ansC, nowC);
			if (nowC < 0) nowC = 0;
		}

		int sum = 0;
		for (int i = 0; i < N; i += 2)
			sum += A[i];
		cout << sum + max(ansB, ansC) << endl;
	}
}

