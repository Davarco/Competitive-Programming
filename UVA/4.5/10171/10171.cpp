#include <bits/stdc++.h>

using namespace std;

#define INF 100000000

int N;

int main()
{
	while (cin >> N)
	{
		if (N == 0)
			break;

		int GY[26][26], GM[26][26];
		for (int a = 0; a < 26; a++)
			for (int b = 0; b < 26; b++)
				GY[a][b] = INF, GM[a][b] = INF;

		for (int n = 0; n < N; n++)
		{
			char R, D, A, B; 
			int C;
			cin >> R >> D >> A >> B >> C;
			if (R == 'Y')
			{
				if (D == 'U')
					GY[A-'A'][B-'A'] = C;
				else if (D == 'B')
					GY[A-'A'][B-'A'] = C, GY[B-'A'][A-'A'] = C;
			}
			else if (R == 'M')
			{
				if (D == 'U')
					GM[A-'A'][B-'A'] = C;
				else if (D == 'B')
					GM[A-'A'][B-'A'] = C, GM[B-'A'][A-'A'] = C;
			}
		}

		for (int n = 0; n < 26; n++)
			for (int a = 0; a < 26; a++)
				for (int b = 0; b < 26; b++)
					GY[a][b] = min(GY[a][b], GY[a][n] + GY[n][b]);

		for (int n = 0; n < 26; n++)
			for (int a = 0; a < 26; a++)
				for (int b = 0; b < 26; b++)
					GM[a][b] = min(GM[a][b], GM[a][n] + GM[n][b]);

		for (int n = 0; n < 26; n++)
			GY[n][n] = 0, GM[n][n] = 0;

		char me, prof;
		cin >> me >> prof;

		vector<int> best = { 0 };
		for (int n = 1; n < 26; n++)
		{
			if (GY[me-'A'][n] + GM[prof-'A'][n] == GY[me-'A'][best[0]] + GM[prof-'A'][best[0]])
				best.push_back(n);		
			if (GY[me-'A'][n] + GM[prof-'A'][n] < GY[me-'A'][best[0]] + GM[prof-'A'][best[0]])
				best.clear(), best.push_back(n);
		}
		int dist = GY[me-'A'][best[0]] + GM[prof-'A'][best[0]];
		if (dist > INF - 100000)
			cout << "You will never meet." << endl;
		else
		{
			printf("%d ", dist);
			for (int i = 0; i < best.size(); i++)
				printf("%c%c", best[i] + 'A', (i == best.size()-1 ? '\n' : ' '));
		}
	}
}
