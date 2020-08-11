#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int N, M;

int main()
{
	cin >> N >> M;
	vi D[N];
	for (int m = 0; m < M; m++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (a > b)
			swap(a, b);
		D[a].push_back(b);
	}

	int L = INT_MAX, R = INT_MIN, count = 0;
	for (int n = 0; n < N; n++)
	{
		if (D[n].size() == 0)
			continue;
		int nL = n, nR = *min_element(D[n].begin(), D[n].end())-1;
		if (nR < L || nL > R)
			count++, L = nL, R = nR;
		else
			L = max(L, nL), R = min(R, nR);
	}
	cout << count << endl;
}

