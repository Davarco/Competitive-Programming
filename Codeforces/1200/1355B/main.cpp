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
		vi E(N);
		for (int n = 0; n < N; n++)
			cin >> E[n];
		sort(E.begin(), E.end());

		int now = 0, count = 0;
		for (int n = 0; n < N; n++)
		{
			now++;
			if (E[n] == now)
				count++, now = 0;
		}
		cout << count << endl;
	}
}

