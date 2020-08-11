#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int main()
{
	int N, M;
	cin >> N >> M;

	vvi mat0(N, vi(M));
	vvi mat1(N, vi(M));
	for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) cin >> mat0[n][m];
	for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) cin >> mat1[n][m];

	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			if (mat0[r][c] > mat1[r][c]) 
				swap(mat0[r][c], mat1[r][c]);

	for (int r = 0; r < N; r++)
		for (int c = 0; c < M-1; c++)
			if (mat0[r][c+1] <= mat0[r][c] || mat1[r][c+1] <= mat1[r][c])
			{
				cout << "Impossible" << endl;
				return 0;
			}

	for (int c = 0; c < M; c++)
		for (int r = 0; r < N-1; r++)
			if (mat0[r+1][c] <= mat0[r][c] || mat1[r+1][c] <= mat1[r][c])
			{
				cout << "Impossible" << endl;
				return 0;
			}

	cout << "Possible" << endl;
}

