#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int T, N, K, A;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;
		set<int> S;
		for (int n = 0; n < N; n++)
			cin >> A, S.insert(A);

		if (S.size() > K)
		{
			cout << -1 << endl;
			continue;
		}
		cout << N*K << endl;
		vi B;
		for (int n = 0; n < N; n++)
		{
			for (int s: S)
				B.push_back(s);
			for (int i = 0; i < K-S.size(); i++)
				B.push_back(1);
		}
		for (int i = 0; i < B.size(); i++)
			cout << B[i] << (i == B.size()-1 ? '\n' : ' ');
	}
}

