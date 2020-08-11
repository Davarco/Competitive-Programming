#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int P, R;

int main()
{
	int T = 0;
	while (cin >> P >> R)
	{
		if (P == 0 && R == 0)
			break;

		vvi G(P, vi(P, INF));
		for (int p = 0; p < P; p++)
			G[p][p] = 0;

		int id = 0;
		map<string, int> name;
		for (int r = 0; r < R; r++)
		{
			string a, b;
			cin >> a >> b;
			if (name.find(a) == name.end())
				name[a] = id++;
			if (name.find(b) == name.end())
				name[b] = id++;
			G[name[a]][name[b]] = 1, G[name[b]][name[a]] = 1;
		}

		for (int n = 0; n < P; n++)
			for (int a = 0; a < P; a++)
				for (int b = 0; b < P; b++)
					G[a][b] = min(G[a][b], G[a][n] + G[n][b]);

		int top = -INF;
		for (int a = 0; a < P; a++)
			for (int b = 0; b < P; b++)
				top = max(top, G[a][b]);

		if (top != INF)
			printf("Network %d: %d\n\n", ++T, top);
		else
			printf("Network %d: DISCONNECTED\n\n", ++T);
	}
}
