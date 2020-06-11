#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Q;
string S, SS;

vector<int> indices[256];
vector<int> start;

int search(int i, int prev)
{
	char c = SS[i];
	if (start[c] > indices[c].size()-1 || prev > indices[c][indices[c].size()-1])
		return -1;
	int a = start[c], b = indices[c].size();
	/*
	for (int k = a; k < b; k++)
		if (indices[c][k] > prev)
		{
			start[c] = k+1;
			return indices[c][k];
		}
	*/
	while (a < b)
	{
		int m = (a+b)/2;
		// printf("(%d, %d) (%d, %d) (%d, %d)\n", a, indices[c][a], b, indices[c][b], m, indices[c][m]);
		if (indices[c][m] <= prev)
		{
			a = m + 1;
		}
		else
		{
			b = m;
		}
	}
	start[c] = a+1;
	return indices[c][a];
}

int main()
{
	cin >> S >> Q;
	for (int i = 0; i < S.length(); i++)
		indices[S[i]].push_back(i);
	/*
	for (int i = 0; i < 256; i++)
	{
		if (indices[i].size() == 0) continue;
		cout << (char) i << " "; 
		for (int j = 0; j < indices[i].size(); j++) cout << indices[i][j] << " "; cout << endl;
	}
	*/
	for (int q = 0; q < Q; q++)
	{
		cin >> SS;
		int prev = -1;
		int bottom, top=-1;

		start.assign(256, 0);
		for (int i = 0; i < SS.length(); i++)
		{
			prev = search(i, prev);			
			// cout << prev << endl;
			if (prev == -1)
				break;
			if (i == 0)
				bottom = prev;
			if (i == SS.length()-1)
				top = prev;
		}
		if (top == -1)
			cout << "Not matched" << endl;
		else
			printf("Matched %d %d\n", bottom, top);
	}
}
