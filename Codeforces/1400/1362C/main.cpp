#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define int LL
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
		int ones = 0;
		for (int n = 0; n < 64; n++)
			if ((N >> n) & 1 == 1)
				ones++;
		cout << N*2 - ones << endl;
	}
}

