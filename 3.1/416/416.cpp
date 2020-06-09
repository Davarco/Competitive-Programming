#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int digit[10][7] = 
{ { 1, 1, 1, 1, 1, 1, 0 }, 
  { 0, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 0, 1, 1, 0, 1 },
  { 1, 1, 1, 1, 0, 0, 1 },
  { 0, 1, 1, 0, 0, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1 } };

vector<vector<int>> sequence;
vector<int> burned;

bool DFS(int n, int d)
{
	if (d < 0) return false;
	if (n == N) return true;
	bool possible = false;
	bool flag = true;
	vector<int> temp;
	for (int i = 0; i < 7; i++)
		if ((burned[i] && sequence[n][i] == 1) || digit[d][i] - sequence[n][i] == -1)
			flag = false;
		else if (sequence[n][i] - digit[d][i] == -1 && !burned[i])
			temp.push_back(i);
	if (flag) 
	{
		for (int i = 0; i < temp.size(); i++) burned[temp[i]] = 1;
		if ((d == 0 && n == N-1) || DFS(n+1, d-1))
			possible = true;
		for (int i = 0; i < temp.size(); i++) burned[temp[i]] = 0;
	}
	return possible;
}

int main()
{
	int c = 0;
	while (cin >> N)
	{
		if (N == 0) break;
		
		sequence.assign(N, vector<int>(7));
		burned.assign(7, 0);
		for (int n = 0; n < N; n++)
		{
			string in; cin >> in;
			for (int i = 0; i < 7; i++)
				if (in[i] == 'Y') sequence[n][i] = 1;
				else sequence[n][i] = 0;
		}

		bool flag = true;
		for (int d = 0; d < 10; d++)
			if (DFS(0, d))
			{
				cout << "MATCH" << endl;
				flag = false;
				break;
			}
		if (flag) cout << "MISMATCH" << endl;
	}
}
