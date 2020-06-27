#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

typedef long long LL;

int T, A, B, C;
LL prism[20][20][20];

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> A >> B >> C;
		for (int a = 0; a < A; a++) for (int b = 0; b < B; b++) for (int c = 0; c < C; c++)
		{
			cin >> prism[a][b][c];
			if (a > 0) prism[a][b][c] += prism[a-1][b][c];
			if (b > 0) prism[a][b][c] += prism[a][b-1][c];
			if (a > 0 && b > 0) prism[a][b][c] -= prism[a-1][b-1][c];
		}

		LL ans = LLONG_MIN;
		for (int a0 = 0; a0 < A; a0++) for (int b0 = 0; b0 < B; b0++)
			for (int a1 = a0; a1 < A; a1++) for (int b1 = b0; b1 < B; b1++)
			{
				LL sum = 0;
				for (int c = 0; c < C; c++)
				{
					sum += prism[a1][b1][c];
					if (a0 > 0) sum -= prism[a0-1][b1][c];
					if (b0 > 0) sum -= prism[a1][b0-1][c];
					if (a0 > 0 && b0 > 0) sum += prism[a0-1][b0-1][c];
					ans = max(ans, sum);
					if (sum < 0) sum = 0;
				}
			}
		cout << ans << endl;
		if (t != T-1) cout << endl;
	}
}

