#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

vvi G_nonweighted = {
	{ 1, 4 }, { 0, 2, 5 }, { 1, 3, 6 }, { 2, 7 }, { 0, 8 }, { 1, 6, 10 }, { 2, 5, 11 }, { 3, 12 }, 
	{ 4, 9 }, { 8, 10 }, { 5, 9, 11 }, { 6, 10, 12 }, { 7, 11 }
};

// O(V + E) w/ ADJLIST, O(V^2) with ADJMATRIX
void dfs_iterative()
{
	stack<int> s;	
	vector<char> visited(G_nonweighted.size(), false);

	s.push(0);
	while (s.size() > 0) 
	{
		int n = s.top(); s.pop();
		if (!visited[n]) visited[n] = true; else continue;
		cout << n << " ";
		for (int i = 0; i < G_nonweighted[n].size(); i++)
		{
			int next = G_nonweighted[n][i];
			if (!visited[next]) s.push(next);
		}
	}
	cout << endl;
}

vector<char> dfs_visited;
void dfs_recursive_helper(int n)
{
	cout << n << " ";
	dfs_visited[n] = true;
	for (int i = 0; i < G_nonweighted[n].size(); i++)
	{
		int next = G_nonweighted[n][i];
		if (!dfs_visited[next]) dfs_recursive_helper(next);
	}
}
void dfs_recursive()
{
	dfs_visited.assign(G_nonweighted.size(), false);
	dfs_recursive_helper(0);
	cout << endl;
}

// O(V + E) w/ ADJLIST, O(V^2) with ADJMATRIX
void bfs()
{
	queue<int> q;
	vector<char> visited(G_nonweighted.size(), false);

	q.push(5);
	while (q.size() > 0)
	{
		int n = q.front(); q.pop();
		if (!visited[n]) visited[n] = true; else continue;
		cout << n << " ";
		for (int i = 0; i < G_nonweighted[n].size(); i++)
		{
			int next = G_nonweighted[n][i];
			if (!visited[next]) q.push(next);
		}
	}
	cout << endl;
}

// Finding Connected Components - DFS, BFS, or Union-Find Disjoint Structure
// Straightforward implementation, not shown here

// Flood Fill - DFS, BFS
// Straightforward implementation, not shown here

// DFS implementation is straightforward, remember to keep sort in reverse order before output
// Modified BFS (Kahn's) ensures that the vertices are in linear order
void toposort_on_dag()
{
	// For each vertex v, G[v] contains a set of vertices that must precede v.
	set<int> G[10] = {
		{ 1 }, { 7 }, {}, { 6, 7 }, { 5, 7 }, {}, { 5 }, { 2 }, { 2 }, { 1, 2 }
	};
	vector<int> topo;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int n = 0; n < 10; n++)
		if (G[n].size() == 0)
			pq.push(n);
	while (pq.size() > 0)
	{
		int v = pq.top(); pq.pop();
		topo.push_back(v);
		for (int n = 0; n < 10; n++)
			if (G[n].count(v) > 0)
			{
				G[n].erase(v);
				if (G[n].size() == 0) pq.push(n);
			}
	}
	for (int i = 0; i < topo.size(); i++)
		cout << topo[i] << " "; cout << endl;
}

// Bipartite Graph Check - BFS
// Straightforward implementation, not shown here

// Better known as "Finding Articulation Points and Bridges on an Undirected Graph"
vi dpb_num, dpb_low, dpb_parent, dpb_vertex; int dpb_counter, dpb_rootch;
vvi G_dpb = {{ 1 }, { 0, 2, 3 }, { 1 }, { 1 }, { 1, 5 }, { 1, 4 }};
void disconnecting_points_and_bridges_helper(int u)
{
	dpb_num[u] = dpb_low[u] = dpb_counter++;
	for (int i = 0; i < G_dpb[u].size(); i++)
	{
		int v = G_dpb[u][i];
		if (dpb_num[v] == -1)
		{
			dpb_parent[v] = u;
			if (u == 0) dpb_rootch += 1; // Assume graph is connected.
			disconnecting_points_and_bridges_helper(v);
			if (dpb_low[v] >= dpb_num[u]) dpb_vertex[u] = true;
			if (dpb_low[v] > dpb_num[u]) ; // Edge u-v is a bridge.
			dpb_low[u] = min(dpb_low[u], dpb_low[v]);
		}
		else if (v != dpb_parent[u])
			dpb_low[u] = min(dpb_low[u], dpb_num[v]);
	}
}
void disconnecting_points_and_bridges()
{
	int N = G_dpb.size();
	dpb_num.assign(N, -1), dpb_low.assign(N, 0), dpb_parent.assign(N, 0), dpb_vertex.assign(N, 0);
	dpb_counter = 0, dpb_rootch = 0;
	disconnecting_points_and_bridges_helper(0);
	dpb_vertex[0] = dpb_rootch > 1;
	for (int i = 0; i < N; i++) if (dpb_vertex[i]) cout << i << " "; cout << endl;
}

// Finding Strongly Connected Components - DFS

int main()
{
	dfs_iterative();
	dfs_recursive();
	bfs();
	toposort_on_dag();
	disconnecting_points_and_bridges();
}


