#include <bits/stdc++.h>

using namespace std;

#define INF 100000000 

int main()
{
	int C = 0;
	while (true)
	{
		int G[100][100];
		for (int a = 0; a < 100; a++) for (int b = 0; b < 100; b++) G[a][b] = INF;

		set<int> nodes;
		int a, b, first = true;
		while (cin >> a >> b)
			if (a == 0 && b == 0)
				if (first) return 0; else break;
			else 
				a -= 1, b -= 1, G[a][b] = 1, first = false, nodes.insert(a), nodes.insert(b);

		for (auto n = nodes.begin(); n != nodes.end(); n++)
			for (auto a = nodes.begin(); a != nodes.end(); a++)
				for (auto b = nodes.begin(); b != nodes.end(); b++)
					G[*a][*b] = min(G[*a][*b], G[*a][*n] + G[*n][*b]);

		int count = 0; 
		double sum = 0;
		for (auto a = nodes.begin(); a != nodes.end(); a++)
			for (auto b = nodes.begin(); b != nodes.end(); b++)
				if (*a != *b)
					sum += G[*a][*b], count += 1;

		printf("Case %d: average length between pages = %0.003lf clicks\n", ++C,
				sum/(double)(count));
	}
}
