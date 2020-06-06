#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	int M;
	while (cin >> M)
	{
		vector<string> grid(M);
		for (int m = 0; m < M; m++) cin >> grid[m];

		int furthest = INT_MIN;
		for (int a = 0; a < M; a++)
			for (int b = 0; b < M; b++)
			{
				if (grid[a][b] != '1') continue;
				int shortest = INT_MAX;
				for (int c = 0; c < M; c++)
					for (int d = 0; d < M; d++)
						if (grid[c][d] == '3')
						{
							int distance = abs(a-c) + abs(b-d);
							if (distance < shortest) shortest = distance;
						}
				if (shortest > furthest) furthest = shortest;
			}
		cout << furthest << endl;
	}
}
