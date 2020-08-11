#include <bits/stdc++.h>

using namespace std;

#define INF 100000000

int N;

int main()
{
	/*
	 * This is a p insane FW question.
	 */
	while (cin >> N)
	{
		double G[20][20][20]; int P[20][20][20];
		for (int a = 0; a < 20; a++) for (int b = 0; b < 20; b++) for (int c = 0; c < 20; c++)
			G[a][b][c] = 0, P[a][b][c] = 0;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				if (r != c) cin >> G[r][c][0]; else G[r][c][0] = 1.;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				P[r][c][0] = r;

		for (int s = 1; s < N; s++)
			for (int n = 0; n < N; n++)
				for (int a = 0; a < N; a++)
					for (int b = 0; b < N; b++)
					{
						double temp = G[a][n][s-1] * G[n][b][0];
						if (temp > G[a][b][s])
							G[a][b][s] = temp, P[a][b][s] = n;
					}

		int found = false;
		for (int s = 1; s < N; s++)
		{
			for (int n = 0; n < N; n++)
				if (G[n][n][s] > 1.01)
				{
					vector<int> seq;
					seq.push_back(n);
					int a = n;
					for (int i = 0; i <= s; i++)
						a = P[n][a][s-i], seq.push_back(a);
					reverse(seq.begin(), seq.end());
					for (int i = 0; i < seq.size(); i++)
						cout << seq[i]+1 << (i == seq.size()-1 ? '\n' : ' ');
					found = true;
					break;
				}

			if (found)
				break;
		}

		if (!found)
			cout << "no arbitrage sequence exists" << '\n';
	}
}
