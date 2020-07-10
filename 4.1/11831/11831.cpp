#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, S;
string grid[100];
string instructions;

int main()
{
	while (cin >> N >> M >> S)
	{
		if (N == 0 && M == 0 && S == 0) break;
		for (int n = N-1; n >= 0; n--) cin >> grid[n];
		cin >> instructions;

		int r, c, d; char dir;
		for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) 
			if (grid[n][m] == 'N' || grid[n][m] == 'S' || grid[n][m] == 'L' || grid[n][m] == 'O')
				r = n, c = m, dir = grid[n][m];
		if (dir == 'N') d = 0;
		else if (dir == 'S') d = 2;
		else if (dir == 'L') d = 1;
		else d = 3;
		
		int count = 0;
		for (int s = 0; s < S; s++)
		{
			if (instructions[s] == 'D') 
				d = (d+1) % 4;
			if (instructions[s] == 'E')
				d = (d-1) % 4;
			if (d < 0) d += 4;
			if (instructions[s] == 'F')
			{
				int dr, dc;
				if (d == 0) dr = 1, dc = 0;
				if (d == 1) dr = 0, dc = 1;
				if (d == 2) dr = -1, dc = 0;
				if (d == 3) dr = 0, dc = -1;
				if (r+dr >= N || r+dr < 0 || c+dc >= M || c+dc < 0 || grid[r+dr][c+dc] == '#')
					continue;
				if (grid[r+dr][c+dc] == '*')
				{
					grid[r+dr][c+dc] = '.';
					count += 1;
				}
				r += dr; c += dc;
			}
		}
		cout << count << endl;
	}
}
