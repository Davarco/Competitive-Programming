#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int T, N;
vi A;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		A.assign(N, 0);
		for (int n = 0; n < N; n++)
			cin >> A[n];
		cout << (A[0] > A[N-1] ? "NO" : "YES") << endl;
	}
}

