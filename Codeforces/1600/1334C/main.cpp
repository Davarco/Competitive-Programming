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
int A[300001], B[300001];

signed main()
{
	scanf("%lld\n", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%lld\n", &N);
		for (int n = 0; n < N; n++)
			scanf("%lld %lld\n", &A[n], &B[n]);

		int best = LLONG_MAX, ans = 0;
		for (int n = 0; n < N; n++)
		{
			int next = (n + 1) % N;
			int save = min(B[n], A[next]);
			ans += A[next] - save;
			best = min(best, save);	
		}

		printf("%lld\n", ans + best);
	}
}

/*
vi K(N);
for (int n = 0; n < N; n++)
{
	int i = 0, net = 0;
	while (i < N)
	{
		int cur = (n+i) % N, nex = (n+i+1) % N;
		if (B[cur] >= A[nex])
			net += (i != N-1 ? A[nex] : 0), i++;
		else
		{
			net += (i != N-1 ? B[cur] : 0);
			break;
		}
	}
	net -= A[n];
	K[n] = net;
}

int best = 0;
for (int i = 0; i < N; i++)
	if (K[i] > K[best])
		best = i;
int i = 0, prev = 0, shots = 0;
while (i < N)
{
	int cur = (best+i) % N;
	if (prev < A[cur])
		shots += A[cur] - prev;
	prev = B[cur], i++;
}
PLIST(K, N);
cout << shots << endl;
*/
