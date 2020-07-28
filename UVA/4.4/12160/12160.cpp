#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

int L, U, R;

int main()
{
	int T = 0;
	while (cin >> L >> U >> R)
	{
		if (L == 0 && U == 0 && R == 0)
			break;
		vi buttons(R);
		for (int r = 0; r < R; r++)
			cin >> buttons[r];

		queue<int> q;
		vi visited(10000, -1);
		visited[L] = 0, q.push(L);
		while (q.size() > 0)
		{
			int u = q.front(); q.pop();
			for (int r = 0; r < R; r++)
			{
				int v = (u + buttons[r]) % 10000;
				if (visited[v] == -1)
				{
					visited[v] = visited[u] + 1;
					q.push(v);
				}
			}
		}
		if (visited[U] == -1)
			printf("Case %d: Permanently Locked\n", ++T);
		else
			printf("Case %d: %d\n", ++T, visited[U]);
	}
}
