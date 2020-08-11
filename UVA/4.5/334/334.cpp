#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int C, E, M;

int main()
{
	int T = 0;
	while (cin >> C)
	{
		if (C == 0) break;

		vvi G(200, vi(200));

		int i = 0;
		map<string, int> m;
		map<int, string> inv;
		for (int c = 0; c < C; c++)
		{
			cin >> E;
			vector<int> seq(E);
			for (int e = 0; e < E; e++)
			{
				string in;
				cin >> in;
				if (m.find(in) == m.end())
					inv[i] = in, m[in] = i++;
				seq[e] = m[in];
			}
			for (int e = 0; e < E-1; e++)
				G[seq[e]][seq[e+1]] = 1;		
		}	
		cin >> M;
		while (M--)
		{
			string a, b;
			cin >> a >> b;
			if (m.find(a) == m.end())
				inv[i] = a, m[a] = i++;
			if (m.find(b) == m.end())
				inv[i] = b, m[b] = i++;
			G[m[a]][m[b]] = 1;
		}

		int N = i;
		for (int n = 0; n < N; n++)
			for (int a = 0; a < N; a++)
				for (int b = 0; b < N; b++)
					G[a][b] |= (G[a][n] & G[n][b]);

		vii events;
		int count = 0;
		for (int a = 0; a < N; a++)
			for (int b = 0; b < a; b++)
				if (G[a][b] + G[b][a] == 0)
					events.push_back(ii(b, a)), count += 1;

		if (count != 0)
		{
			printf("Case %d, %d concurrent events:\n", ++T, count);
			for (int a = 0; a < min(count, 2); a++)
				printf("(%s,%s) ", inv[events[a].first].c_str(), inv[events[a].second].c_str()); 
			printf("\n");
		}
		else
			printf("Case %d, no concurrent events.\n", ++T);
	}
}
