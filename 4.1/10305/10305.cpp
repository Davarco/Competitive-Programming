#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> edges[101];
vector<int> now;
char vis[101];

void dfs(int n)
{
	vis[n] = true;
	for (int i = 0; i < edges[n].size(); i++)
		if (!vis[edges[n][i]])
			dfs(edges[n][i]);
	now.push_back(n);
}

int main()
{
	while (cin >> N >> M)
	{
		if (N == 0 && M == 0) break;
		for (int n = 1; n <= N; n++) 
			edges[n].clear();
		now.clear();
		for (int n = 1; n <= N; n++)
			vis[n] = false;
		for (int m = 1; m <= M; m++)
		{
			int a, b; cin >> a >> b;
			edges[a].push_back(b);
		}
		for (int n = 1; n <= N; n++)
			if (!vis[n])
				dfs(n);
		reverse(now.begin(), now.end());
		for (int i = 0; i < now.size(); i++)
			if (i != now.size()-1)
				cout << now[i] << " ";
			else
				cout << now[i] << endl;
	}
}
