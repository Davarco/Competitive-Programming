#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int T, N;
int torus[150][150];

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int r = 0; r < N*2; r++) for (int c = 0; c < N*2; c++)
		{
			if (r < N && c < N) 
			{
				cin >> torus[r][c];
				torus[r+N][c] = torus[r][c+N] = torus[r+N][c+N] = torus[r][c];
			}
			if (r > 0) torus[r][c] += torus[r-1][c];
			if (c > 0) torus[r][c] += torus[r][c-1];
			if (r > 0 && c > 0) torus[r][c] -= torus[r-1][c-1];
		}

		int ans = INT_MIN;
		for (int r0 = 0; r0 < N; r0++) for (int r1 = r0; r1 < r0+N; r1++)
			for (int c0 = 0; c0 < N; c0++) for (int c1 = c0; c1 < c0+N; c1++)
			{
				int subrect = torus[r1][c1];
				if (r0 > 0) subrect -= torus[r0-1][c1];
				if (c0 > 0) subrect -= torus[r1][c0-1];
				if (r0 > 0 && c0 > 0) subrect += torus[r0-1][c0-1];
				ans = max(ans, subrect);
			}
		cout << ans << endl;
	}
}
