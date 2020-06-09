#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

typedef vector<vector<char>> vvi;

int T, K;
int k;
vvi grid0, grid1;
vector<char> vec0;
vector<char> vec1;
bool flag;
unordered_set<string> used;

void search1(int c)
{
	if (c == 5)
	{
		k += 1;
		if (k == K)
		{
			for (int i = 0; i < 5; i++) cout << vec1[i]; cout << endl;
			flag = true;
		}
		return;
	}
	for (int r = 0; r < 6; r++)
	{
		if (r > 0 && grid1[r][c] == grid1[r-1][c]) continue;
		if (grid1[r][c] != vec0[c]) continue;
		vec1.push_back(grid1[r][c]);
		search1(c+1);
		vec1.pop_back();
	}
}

void search0(int c)
{
	if (c == 5)
	{
		vec1.clear();
		search1(0);
		return;
	}
	for (int r = 0; r < 6; r++)
	{
		if (r > 0 && grid0[r][c] == grid0[r-1][c]) continue;
		vec0.push_back(grid0[r][c]);
		search0(c+1);
		vec0.pop_back();
	}
}

int main()
{
	scanf("%d\n", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%d\n", &K);
		k = 0;
		vec0.clear();

		flag = false;
		vvi temp(5, vector<char>(6));
		for (int r = 0; r < 6; r++) 
			scanf("%c%c%c%c%c\n", &temp[0][r], &temp[1][r], &temp[2][r], &temp[3][r], &temp[4][r]);
		for (int r = 0; r < 5; r++) 
			sort(temp[r].begin(), temp[r].end());
		grid0.assign(6, vector<char>(5));
		for (int r = 0; r < 5; r++)
			for (int c = 0; c < 6; c++)
				grid0[c][r] = temp[r][c];
		for (int r = 0; r < 6; r++) 
			scanf("%c%c%c%c%c\n", &temp[0][r], &temp[1][r], &temp[2][r], &temp[3][r], &temp[4][r]);
		for (int r = 0; r < 5; r++) 
			sort(temp[r].begin(), temp[r].end());
		grid1.assign(6, vector<char>(5));
		for (int r = 0; r < 5; r++)
			for (int c = 0; c < 6; c++)
				grid1[c][r] = temp[r][c];

		search0(0);
		if (!flag)
			cout << "NO" << endl;
	}
}

