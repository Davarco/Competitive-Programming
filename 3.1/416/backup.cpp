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

int convert(const vector<int> &v)
{
	for (int d = 0; d < 10; d++)
	{
		bool flag = true;
		for (int i = 0; i < 7; i++)
			if (v[i] != digit[d][i])
				flag = false;
		if (flag)
			return d;
	}
	return -100;
}

bool is_countdown()
{
	int prev = convert(sequence[0]);
	if (prev == -1) return false;
	for (int i = 0; i < N-1; i++)
	{
		int next = convert(sequence[i]);
		if (next == -100 || next != prev-1)
			return false;
		else
			prev = next;
	}
	return true;
}

void unchange(int i)
{
	for (int n = 0; n < N; n++)
		sequence[n][i] = 0;
}

bool change(int i)
{
	for (int n = 0; n < N; n++)
		if (sequence[n][i] == 1)
			return false;
	for (int n = 0; n < N; n++)
		sequence[n][i] = 1;
	return true;
}

bool DFS(int a)
{
	if (a == 7) 
		return false;

	if (change(a))
	{
		if (is_countdown())
			return true;
		else if (DFS(a+1))
			return true;
		unchange(a);
	}

	if (is_countdown())
		return true;
	else if (DFS(a+1))
		return true;
	return false;
}

int main()
{
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

		if (DFS(0))
			cout << "MATCH" << endl;
		else
			cout << "MISMATCH" << endl;
	}
}
