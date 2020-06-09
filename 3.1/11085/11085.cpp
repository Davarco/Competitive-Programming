#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi valid;

vi row(8, -1);

void find_valid(int C)
{
	if (C == 8)
	{
		valid.push_back(row);
	}
	else
	{
		for (int r = 0; r < 8; r++)
		{
			bool flag = true;
			for (int c = 0; c < C; c++)
				if (row[c] == r || abs(row[c]-r) == abs(c-C))
				{
					flag = false;
					break;
				}
			if (flag) 
			{
				row[C] = r;
				find_valid(C+1);
			}
		}
	}
}

int main()
{
	find_valid(0);

	vector<int> R(8);
	int cse = 0;
	while (cin >> R[0] >> R[1] >> R[2] >> R[3] >> R[4] >> R[5] >> R[6] >> R[7])	
	{
		for (int i = 0; i < 8; i++) R[i]--;
		int best = INT_MAX;
		for (int i = 0; i < valid.size(); i++)
		{
			int count = 0;
			for (int c = 0; c < 8; c++) if (valid[i][c] != R[c]) count += 1;
			if (count < best) best = count;
		}
		printf("Case %d: %d\n", ++cse, best);
	}
}
