#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

int N, M, Q, L, U;
vvi R, C;

int main()
{
	while (cin >> N >> M)
	{
		if (N == 0 && M == 0) break;
		R.assign(N, vector<int>(M, 0));
		C.assign(M, vector<int>(N, 0));
		for (int r = 0; r < N; r++) for (int c = 0; c < M; c++) { cin >> R[r][c]; C[c][r] = R[r][c]; } 
		cin >> Q;
		for (int q = 0; q < Q; q++)
		{
			cin >> L >> U;	
			int best_n = -1;
			for (int r = 0; r < N; r++)
			{
				int min_c = lower_bound(R[r].begin(), R[r].end(), L) - R[r].begin();
				int n = 0;
				while (r+n < N && min_c+n < M && R[r+n][min_c+n] <= U)
					n += 1;
				if (n > best_n)
					best_n = n;
			}
			cout << best_n << endl;
		}
		cout << '-' << endl;
	}
}
