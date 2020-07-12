#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<char>> matrix)
{
	int N = matrix.size();
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
			printf("%c", matrix[r][c]);
		printf("\n");
	}
}

void rotate90(vector<vector<char>> &matrix)
{
	int N = matrix.size();
	for (int r = 0; r < N; r++)
		for (int c = r+1; c < N; c++)
			swap(matrix[r][c], matrix[c][r]);
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N/2; c++)
			swap(matrix[r][c], matrix[r][N-c-1]);
}

int count(vector<vector<char>> &big, vector<vector<char>> &little)
{
	int N = big.size() - little.size() + 1;
	int n = little.size();
	int count = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++) 
		{
			bool flag = true;
			for (int r0 = 0; r0 < n; r0++)
				for (int c0 = 0; c0 < n; c0++)
					if (big[r+r0][c+c0] != little[r0][c0])
						flag = false;
			if (flag)
				count += 1;
		}
	}
	return count;
}

int main()
{
	while (true)
	{
		int N, n;
		scanf("%d %d\n", &N, &n);
		if (N == 0 && n == 0)
			break;

		vector<vector<char>> big(N, vector<char>(N));
		vector<vector<char>> little(n, vector<char>(n));
		for (int r = 0; r < N; r++)
		{
			string str;
			getline(cin, str);
			for (int c = 0; c < N; c++)
				big[r][c] = str[c];
		}
		for (int r = 0; r < n; r++)
		{
			string str;
			getline(cin, str);
			for (int c = 0; c < n; c++)
				little[r][c] = str[c];
		}

		int c0 = count(big, little);
		rotate90(little);
		int c1 = count(big, little);
		rotate90(little);
		int c2 = count(big, little);
		rotate90(little);
		int c3 = count(big, little);
		printf("%d %d %d %d\n", c0, c1, c2, c3);
	}
}
