#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> heads, heights;

int main()
{
	while (cin >> N >> M)
	{
		heads.assign(N, 0); heights.assign(M, 0);
		for (int n = 0; n < N; n++) cin >> heads[n];
		for (int m = 0; m < M; m++) cin >> heights[m];

		sort(heads.begin(), heads.end());
		sort(heights.begin(), heights.end());
		int now = 0, sum = 0;
		for (int n = 0; n < N; n++)
		{
			bool found = false;
			for (int m = now; m < M; m++) 
				if (heights[m] >= heads[n])
				{
					sum += heights[m];
					now = m + 1;
					found = true;
					break;
				}

			if (!found)
			{
				cout << "Loowater is doomed!" << endl;
				break;
			}
			else if (n == N-1)
			{
				cout << sum << endl;
				break;
			}
		}
	}
}
