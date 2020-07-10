// I died from doing this stupid problem. I need a new career.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int T, R, C, M, N, W;
char water[100][100];

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> C >> R >> M >> N >> W;
		for (int r = 0; r < 100; r++) for (int c = 0; c < 100; c++) water[r][c] = false;
		for (int w = 0; w < W; w++)
		{
			int a, b; cin >> a >> b;
			water[b][a] = true;
		}
		/*
		for (int r = R-1; r >= 0; r--)
		{
			for (int c = 0; c < C; c++) if (water[r][c]) cout << "X"; else cout << ".";
			cout << endl;
		}
		*/
		vector<int> rdir, cdir;
		if (N == 0)
			rdir = { 0, 0 }, cdir = { 1, -1 };
		else if (M == 0)
			rdir = { 1, -1 }, cdir = { 0, 0 };
		else
			rdir = { 1, 1, -1, -1 }, cdir = { 1, -1, 1, -1 };

		vi count(2, 0);
		vvi visited(R, vi(C));
		queue<int> qr, qc;
		qr.push(0); qc.push(0); 
		while (qr.size() > 0 && qc.size() > 0)
		{
			int r = qr.front(), c = qc.front(); qr.pop(); qc.pop();
			if (visited[r][c]) continue;
			visited[r][c] = true;
			int k = 0;
			for (int i = 0; i < rdir.size(); i++)
			{
				int nr = r + rdir[i]*N, nc = c + cdir[i]*M;
				if (nr >= 0 && nr < R && nc >= 0 && nc < C && !water[nr][nc])
				{
					k += 1;
					if (!visited[nr][nc]) qr.push(nr), qc.push(nc);
				}
			}
			if (N != M)
			{
				for (int i = 0; i < rdir.size(); i++)
				{
					int nr = r + cdir[i]*M, nc = c + rdir[i]*N;
					if (nr >= 0 && nr < R && nc >= 0 && nc < C && !water[nr][nc])
					{
						k += 1;
						if (!visited[nr][nc]) qr.push(nr), qc.push(nc);
					}
				}
			}
			count[k%2] += 1;
		}
		printf("Case %d: %d %d\n", t+1, count[0], count[1]);
	}
}
