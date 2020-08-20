#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int T, N, K;
vi A, W;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;
		A.assign(N, 0), W.assign(K, 0);
		for (int n = 0; n < N; n++)
			cin >> A[n];
		for (int k = 0; k < K; k++)
			cin >> W[k];
		sort(A.begin(), A.end());
		sort(W.begin(), W.end());

		int L = N - K, R = N;
		int sum = 0;
		for (int w = 0; w < K; w++)
		{
			sum += A[R-1];
			if (W[w] == 1) 
				sum += A[R-1];
			R--;
			if (W[w] != 1)
				L -= W[w] - 2, sum += A[--L];
		}
		cout << sum << endl;
	}
}

