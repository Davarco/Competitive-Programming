#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

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
		int R = N-1;
		while (R != 0 && A[R] <= A[R-1])
			R--;
		while (R != 0 && A[R] >= A[R-1])
			R--;
		cout << R << endl;
	}
}

