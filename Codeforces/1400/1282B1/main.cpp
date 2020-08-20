#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define PLIST(a, b) \
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');
#define PLIST2(a, b) \
	for (int i = 0; i < b; i++) cout << a << (i == b-1 ? '\n' : ' ');

int T, N, P, K;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> P >> K;
		vi A(N);
		for (int n = 0; n < N; n++)
			cin >> A[n];
		sort(A.begin(), A.end());

		int count0 = 0, m0 = P;
		if (m0 >= A[0])
			count0++, m0 -= A[0];
		for (int i = 2; i < N && m0 >= A[i]; i += 2)
			count0 += 2, m0 -= A[i];

		int count1 = 0, m1 = P;
		for (int i = 1; i < N && m1 >= A[i]; i += 2)
			count1 += 2, m1 -= A[i];

		cout << max(count0, count1) << endl;
	}
}

