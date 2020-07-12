#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N;
int rect[100][100];

int main()
{
	cin >> N;
	for (int r = 0; r < N; r++) for (int c = 0; c < N; c++)
	{
		cin >> rect[r][c];
		if (r > 0) rect[r][c] += rect[r-1][c];
	}

	int ans = INT_MIN;
	for (int r0 = 0; r0 < N; r0++) for (int r1 = r0; r1 < N; r1++)
	{
		int subrect = 0;
		for (int c = 0; c < N; c++)
		{
			subrect += rect[r1][c];
			if (r0 > 0) subrect -= rect[r0-1][c];
			ans = max(ans, subrect);
			if (subrect < 0) subrect = 0;
		}
	}
	cout << ans << endl;
}
