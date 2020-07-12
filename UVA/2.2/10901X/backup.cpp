#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int C;
	cin >> C;

	for (int c = 0; c < C; c++)
	{
		int N, T, M;
		cin >> N >> T >> M;

		queue<int> left;
		queue<int> right;
		for (int m = 0; m < M; m++)
		{
			int t; string side;
			cin >> t >> side;
			if (side == "left")
				left.push(t);
			else
				right.push(t);
		}
		bool L = true;
		int t = 0;
		if (left.size() != 0)
			if (right.size() == 0 || (left.front() <= right.front()))
				t = left.front();
		while (left.size() != 0 || right.size() != 0)
		{
			if (L)
			{
				int n = 0;
				bool flag = false;
				while (n < N && left.size() > 0 && left.front() <= t)
				{
					flag = true;
					cout << t + T << endl;	
					left.pop();
					n += 1;
				}
				if (flag)
					t += T;
				else
					t = max(t + T, right.front() + T);
				L = !L;
			}
			else
			{
				int n = 0; 
				bool flag = false;
				while (n < N && right.size() > 0 && right.front() <= t)
				{
					flag = true;
					cout << t + T << endl;
					right.pop();
					n += 1;
				}
				if (flag)
					t += T;
				else
					t = max(t + T, left.front() + T);
				L = !L;
			}
		}
		if (c != C-1)
			cout << endl;
	}
}
