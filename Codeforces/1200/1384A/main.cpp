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
		vector<int> A(100);
		vector<char> B(100, 'a');
		for (int n = 0; n < N; n++)
			cin >> A[n];
		for (int i = 0; i < 100; i++)
			cout << B[i]; cout << endl;
		for (int n = 0; n < N; n++)
		{
			B[A[n]]++, B[A[n]] = B[A[n]] > 'z' ? 'a' : B[A[n]];
			for (int i = 0; i < 100; i++)
				cout << B[i]; cout << endl;
		}
	}
}

