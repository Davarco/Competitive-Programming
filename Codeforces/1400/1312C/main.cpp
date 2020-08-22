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

int T, N, K;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;
		vi A(N);
		for (int n = 0; n < N; n++)
			cin >> A[n];

		vi U;
		int v = 1, end = *max_element(A.begin(), A.end());
		while (v <= end)
			U.push_back(v), v *= K;

		for (int n = 0; n < N; n++)
		{
			while (A[n] > 0)
			{
				int idx = -1;
				for (int i = 0; i < U.size(); i++)
					if (U[i] <= A[n])
						idx = i;
				if (idx == -1)
				{
					cout << "NO" << endl;
					goto noexist;
				}
				else
					A[n] -= U[idx], U[idx] = LLONG_MAX;
			}
		}

		cout << "YES" << endl;
noexist:
		int a;
	}
}

