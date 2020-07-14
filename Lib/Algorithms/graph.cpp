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

// Finds the points and edges that cause the graph to become disconnected if removed. 
vi cut_num, cut_min, cut_parent, cut_vertex; int cut_counter, cut_rootch;
vvi G_cut = {{ 1 }, { 0, 2, 3 }, { 1 }, { 1 }, { 1, 5 }, { 1, 4 }};
void cut_points_and_edges_helper(int u)
{
	cut_num[u] = cut_min[u] = cut_counter++;
	for (int i = 0; i < G_cut[u].size(); i++)
	{
		int v = G_cut[u][i];
		if (cut_num[v] == -1)
		{
			cut_parent[v] = u;
			if (u == 0) cut_rootch += 1; // Assume graph is connected.
			cut_points_and_edges_helper(v);
			if (cut_min[v] >= cut_num[u]) cut_vertex[u] = true;
			if (cut_min[v] > cut_num[u]) ; // Edge u-v is a bridge.
			cut_min[u] = min(cut_min[u], cut_min[v]);
		}
		else if (v != cut_parent[u])
			cut_min[u] = min(cut_min[u], cut_num[v]);
	}
}
void cut_points_and_edges()
{
	int N = G_cut.size();
	cut_num.assign(N, -1), cut_min.assign(N, 0), cut_parent.assign(N, 0), cut_vertex.assign(N, 0);
	cut_counter = 0, cut_rootch = 0;
	cut_points_and_edges_helper(0);
	cut_vertex[0] = cut_rootch > 1;
	for (int i = 0; i < N; i++) if (cut_vertex[i]) cout << i << " "; cout << endl;
}

// Finds strongly connected components on a directed graph.
vi tarjan_num, tarjan_min, tarjan_vis, tarjan_now; int tarjan_counter;
vvi G_target = {{ 1 }, { 3 }, { 1 }, { 2, 4 }, { 5 }, { 7 }, { 4 }, { 6 }};
void tarjan_helper(int u)
{
	tarjan_num[u] = tarjan_min[u] = tarjan_counter++;
	tarjan_now.push_back(u);
	tarjan_vis[u] = true;
	for (int i = 0; i < G_target[u].size(); i++)
	{
		int v = G_target[u][i];
		if (tarjan_num[v] == -1)
			tarjan_helper(v);
		if (tarjan_vis[v])
			tarjan_min[u] = min(tarjan_min[u], tarjan_min[v]);
	}
	if (tarjan_min[u] == tarjan_num[u])
	{
		while (true)
		{
			int v = tarjan_now.back(); tarjan_now.pop_back();
			tarjan_vis[v] = false;
			cout << v << " "; 
			if (u == v) break;
		}
		cout << endl;
	}
}
void tarjan()
{
	int N = G_target.size();
	tarjan_num.assign(N, -1), tarjan_min.assign(N, 0), tarjan_vis.assign(N, false);
	tarjan_counter = 0;
	for (int i = 0; i < N; i++) if (tarjan_num[i] == -1) tarjan_helper(i);
}

int main()
{
	dfs_iterative();
	dfs_recursive();
	bfs();
	toposort_on_dag();
	cut_points_and_edges();
	tarjan();
}


