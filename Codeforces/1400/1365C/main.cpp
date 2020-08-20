#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int N;

int main()
{
	cin >> N;
	vi p0(N);
	vi p1(N);
	for (int n = 0; n < N; n++)
		cin >> p0[n];
	for (int n = 0; n < N; n++)
		cin >> p1[n];
	vi A(N+1);
	for (int n = 0; n < N; n++)
		A[p0[n]] = n;	
	map<int, int> M;
	for (int n = 0; n < N; n++)
	{
		int i = A[p1[n]];
		int d = (i-n) % N;
		if (d < 0) d += N;
		M[d]++;
	}
	int best = 0;
	for (auto i = M.begin(); i != M.end(); i++)
		if (i->second > best)
			best = i->second;
	cout << best << endl;
}

