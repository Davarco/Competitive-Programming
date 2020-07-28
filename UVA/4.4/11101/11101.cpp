#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int P1, P2;
int vis[2001][2001], tar[2001][2001];
ii dir[4] = { ii(1, 0), ii(0, 1), ii(-1, 0), ii(0, -1) };

int main()
{
	while (cin >> P1)
	{
		if (P1 == 0)
			break;
		memset(vis, 0, sizeof(vis)), memset(tar, 0, sizeof(tar));
		queue<ii> q;
		for (int p = 0; p < P1; p++)
		{
			int a, b;
			cin >> a >> b;
			q.push(ii(a, b));
			vis[a][b] = true;
		}
		cin >> P2;
		for (int p = 0; p < P2; p++)
		{
			int a, b;
			cin >> a >> b;
			tar[a][b] = true;
		}

		int steps = 0, found = 0;
		while (!found)
		{
			int size = q.size();
			for (int i = 0; i < size && !found; i++)
			{
				ii u = q.front(); q.pop();
				if (tar[u.first][u.second])
					found = true;
				else
				{
					for (int d = 0; d < 4; d++)
					{
						ii v = ii(u.first+dir[d].first, u.second+dir[d].second);
						if (v.first < 0 || v.second < 0 || v.first > 2000 || v.second > 2000)
							continue;
						if (vis[v.first][v.second])
							continue;
						vis[v.first][v.second] = true;
						q.push(v);
					}
				}
			}
			if (!found)
				steps += 1;
		}
		cout << steps << endl;
	}
}
