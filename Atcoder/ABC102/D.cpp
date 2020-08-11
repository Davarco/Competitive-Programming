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
	int N;
	cin >> N;
	vector<LL> seq(N);
	for (int n = 0; n < N; n++)
	{
		cin >> seq[n];
		seq[n] += (n == 0 ? 0 : seq[n-1]);
	}
	int L = 0, R = 2;
	LL best = INT_MAX;
	for (int M = 1; M < N-1; M++)
	{
		while (abs((seq[M]-seq[L+1]) - seq[L+1]) <= abs((seq[M]-seq[L]) - seq[L]))
			if (L < M-1)
				L++;
			else
				break;
		while (abs((seq[N-1]-seq[R+1]) - (seq[R+1]-seq[M])) <= abs((seq[N-1]-seq[R]) - (seq[R]-seq[M])))
			if (R < N-1)
				R++;
			else
				break;
		LL a = seq[L], b = seq[M] - seq[L], c = seq[R] - seq[M], d = seq[N-1] - seq[R];
		best = min(best, max({ a, b, c, d }) - min({ a, b, c, d }));
	}
	cout << best << endl;
}

