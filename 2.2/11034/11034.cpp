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
		int L, M;
		cin >> L >> M;
		L *= 100;

		queue<int> left;
		queue<int> right;
		for (int i = 0; i < M; i++)
		{
			int length; string bank;
			cin >> length >> bank;
			if (bank == "left")
				left.push(length);
			else
				right.push(length);
		}

		int crossings = 0;
		bool side = true;
		while (left.size() > 0 || right.size() > 0)
		{
			if (side)
			{
				int s = 0;
				while (left.size() > 0 && s + left.front() < L)
				{
					s += left.front();
					left.pop();
				}
				side = !side;
			}
			else
			{
				int s = 0;
				while (right.size() > 0 && s + right.front() < L)
				{
					s += right.front();
					right.pop();
				}
				side = !side;
			}
			crossings += 1;
		}
		cout << crossings << endl;
	}
}
