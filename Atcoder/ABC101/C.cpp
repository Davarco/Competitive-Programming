#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int main()
{
	int N, K;
	cin >> N >> K;

	vi seq(N);
	for (int n = 0; n < N; n++)
		cin >> seq[n];

	int s = 0;
	for (int n = 0; n < N; n++)
		if (seq[n] < seq[s])
			s = n;

	int steps = 0;
	int L = s, R = s;
	while (L > 0)
	{
		L -= (K-1);
		steps++;
	}
	R += -L;
	while (R < N-1)
	{
		R += (K-1);
		steps++;
	}
	cout << steps << endl;
}

