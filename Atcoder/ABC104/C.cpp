#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int D, G;
vi P, C;

int main()
{
	cin >> D >> G;
	P.assign(D, 0), C.assign(D, 0);

	for (int d = 0; d < D; d++)
		cin >> P[d] >> C[d];

	int best = INT_MAX;
	for (int i = 0; i < (1 << D); i++)
	{
		int temp = G;
		int count = 0;
		for (int d = 0; d < D; d++)
			if ((i >> d) & 1 == 1)
				temp -= C[d], temp -= P[d]*((d+1)*100), count += P[d];

		if (temp <= 0)
		{
			best = min(best, count);
			continue;
		}

		for (int d = D-1; d >= 0; d--)
		{
			if ((i >> d) & 1 == 1) 
				continue;
			int worth = (d+1) * 100;
			int target = (temp % worth == 0) ? temp / worth : temp / worth + 1;
			int used = min(target, P[d]);
			count += used;
			temp -= used * worth;
			if (temp <= 0)
				break;
		}
		best = min(best, count);
	}
	cout << best << endl;
}

