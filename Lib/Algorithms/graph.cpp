#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

// Adjacency List
vvi G_nonweighted = {
	{ 1, 4 }, { 0, 2, 5 }, { 1, 3, 6 }, { 2, 7 }, { 0, 8 }, { 1, 6, 10 }, { 2, 5, 11 }, { 3, 12 }, 
	{ 4, 9 }, { 8, 10 }, { 5, 9, 11 }, { 6, 10, 12 }, { 7, 11 }
};

// O(V + E) w/ AdjList, O(V^2) with AdjMatrix
void dfs_iterative()
{
	stack<int> s;	
	vector<char> visited(G_nonweighted.size(), false);

	s.push(0);
	while (s.size() > 0) 
	{
		int n = s.top(); s.pop();
		if (!visited[n]) visited[n] = true; else continue;
		cout << n << " -> ";
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
	cout << n << " -> ";
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

// O(V + E) w/ AdjList, O(V^2) with AdjMatrix
void bfs()
{
	queue<int> q;
	vector<char> visited(G_nonweighted.size(), false);

	q.push(5);
	while (q.size() > 0)
	{
		int n = q.front(); q.pop();
		if (!visited[n]) visited[n] = true; else continue;
		cout << n << " -> ";
		for (int i = 0; i < G_nonweighted[n].size(); i++)
		{
			int next = G_nonweighted[n][i];
			if (!visited[next]) q.push(next);
		}
	}
	cout << endl;
}

// Finding Connected Components - DFS, BFS, or Union-Find Disjoint Structure

// Flood Fill - DFS, BFS

// Topological Sort on a Directed Acyclic Graph - DFS, BFS (Kahn's Algorithm)

// Bipartite Graph Check - BFS

// Graph Edges Property Check - DFS Spanning Tree

// Finding Articulation Points and Bridges on an Undirected Graph - DFS

// Finding Strongly Connected Components - DFS

int main()
{
	dfs_iterative();
	dfs_recursive();
	bfs();
}


