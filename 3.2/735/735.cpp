#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool visited[61][61][61];

int main()
{
	int score;
	while (cin >> score)
	{
		if (score <= 0) break;

		set<int> s;
		for (int i = 0; i <= 20; i++) { s.insert(i); s.insert(i*2); s.insert(i*3); } s.insert(50);

		for (int a = 0; a < 61; a++) 
			for (int b = 0; b < 61; b++)
				for (int c = 0; c < 61; c++)
					visited[a][b][c] = false;
		
		int combinations = 0;
		int permutations = 0;
		for (auto a = s.begin(); a != s.end(); a++)
		{
			if (*a > score) continue;
			int first = score - *a;
			for (auto b = s.begin(); b != s.end(); b++)
			{
				if (*b > first) continue;
				int second = first - *b;
				for (auto c = s.begin(); c != s.end(); c++)
				{
					if (*c > second) continue;
					int third = second - *c;
					if (third == 0)
					{
						vector<int> p = { *a, *b, *c };
						sort(p.begin(), p.end());
						permutations += 1;
						if (!visited[p[0]][p[1]][p[2]])
						{
							combinations += 1;
							visited[p[0]][p[1]][p[2]] = true;
						}
					}
				}
			}
		}

		if (permutations == 0)
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
		else
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, combinations);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, permutations);
		}
		printf("**********************************************************************\n");
	}
	cout << "END OF OUTPUT" << endl;
}
