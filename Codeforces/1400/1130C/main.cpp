#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };
int N, r0, c0, r1, c1;

int inbound(int r, int c)
{
	return !(r < 0 || r == N || c < 0 || c == N);
}

int main()
{
	cin >> N >> r0 >> c0 >> r1 >> c1;
	r0--, c0--, r1--, c1--;

	vector<string> grid(N);
	for (int n = 0; n < N; n++)
		cin >> grid[n];

	queue<ii> q;
	int vis[N][N];

	vii starts;
	q.push(ii(r0, c0));
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			vis[r][c] = false;
	while (q.size() > 0)
	{
		ii top = q.front(); q.pop();
		int r = top.first, c = top.second;
		if (vis[r][c])
			continue;
		starts.push_back(ii(r, c));
		vis[r][c] = true;
		for (int i = 0; i < 4; i++)
			if (inbound(r+dr[i], c+dc[i]) && !vis[r+dr[i]][c+dc[i]] && grid[r+dr[i]][c+dc[i]] != '1')
				q.push(ii(r+dr[i], c+dc[i]));
	}

	vii dests;
	q.push(ii(r1, c1));
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			vis[r][c] = false;
	while (q.size() > 0)
	{
		ii top = q.front(); q.pop();
		int r = top.first, c = top.second;
		if (vis[r][c])
			continue;
		dests.push_back(ii(r, c));
		vis[r][c] = true;
		for (int i = 0; i < 4; i++)
			if (inbound(r+dr[i], c+dc[i]) && !vis[r+dr[i]][c+dc[i]] && grid[r+dr[i]][c+dc[i]] != '1')
				q.push(ii(r+dr[i], c+dc[i]));
	}

	int best = INT_MAX, dr = 0, dc = 0;
	for (int a = 0; a < starts.size(); a++)
		for (int b = 0; b < dests.size(); b++)
			dr = starts[a].first - dests[b].first, dc = starts[a].second - dests[b].second, best = min(best, dr*dr + dc*dc);
	cout << best << endl;
}

