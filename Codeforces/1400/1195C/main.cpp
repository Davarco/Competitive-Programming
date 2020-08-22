#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define PLIST(a, b) \
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');
#define PLIST2(a, b) \
	for (int i = 0; i < b; i++) cout << a << (i == b-1 ? '\n' : ' ');

int N;

signed main()
{
	cin >> N;
	vi A(N);
	vi B(N);
	for (int n = 0; n < N; n++)
		cin >> A[n];
	for (int n = 0; n < N; n++)
		cin >> B[n];

	vi dp0(N);
	vi dp1(N);
	dp0[N-1] = A[N-1], dp1[N-1] = B[N-1];
	for (int n = 1; n < N; n++)
	{
		int a = dp0[N-n], b = dp1[N-n];
		dp0[N-n-1] = max(A[N-n-1]+b, a);
		dp1[N-n-1] = max(B[N-n-1]+a, b);
	}
	cout << max(dp0[0], dp1[0]) << endl;
}

