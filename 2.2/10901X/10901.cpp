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
		while (left.size() != 0 || right.size() != 0)
		{
			if (L)
			{
				if (left.size() != 0)
					if (right.size() == 0 || (left.front() <= right.front()))
						t = left.front();
					else
						t = right.front();
				else
					t = right.front();
				int n = 0;
				while (n < N && left.size() > 0 && left.front() <= t)
				{
					cout << t + T << endl;	
					left.pop();
					n += 1;
				}
				t += T;
				L = !L;
			}
			else
			{
				if (right.size() != 0)
					if (left.size() == 0 || (right.front() <= left.front()))
						t = right.front();
					else
						t = left.front();
				else
					t = left.front();
				int n = 0; 
				while (n < N && right.size() > 0 && right.front() <= t)
				{
					cout << t + T << endl;
					right.pop();
					n += 1;
				}
				t += T;
				L = !L;
			}
		}
		if (c != C-1)
			cout << endl;
	}
}
