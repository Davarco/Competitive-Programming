#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int dist(int a, int b)
{
	int r0 = a/5, c0 = a%5, r1 = b/5, c1 = b%5;
	return abs(r0-r1) + abs(c0-c1);
}

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N; cin >> N;
		vector<int> pop(25);
		for (int n = 0; n < N; n++)
		{
			int r, c, p; cin >> r >> c >> p;
			pop[r*5+c] = p;
		}

		int squares[5];
		int best_dist = INT_MAX;
		for (int a = 0; a < 25; a++)
			for (int b = a+1; b < 25; b++)
				for (int c = b+1; c < 25; c++)
					for (int d = c+1; d < 25; d++)
						for (int e = d+1; e < 25; e++)
						{
							int temp = 0;
							for (int f = 0; f < 25; f++)
								temp += pop[f] * min({ dist(f, a), dist(f, b), dist(f, c), dist(f, d), dist(f, e) });
							if (temp < best_dist)
							{
								best_dist = temp;
								squares[0] = a; squares[1] = b; squares[2] = c; squares[3] = d; squares[4] = e;
							}
						}
		printf("%d %d %d %d %d\n", squares[0], squares[1], squares[2], squares[3], squares[4]);
	}
}
