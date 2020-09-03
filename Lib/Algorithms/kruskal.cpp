#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

#define Pair(a, b) make_pair(a, b)

// 0-indexed
class UnionFind
{
private:
	vector<int> p, rank, set_size;
	int num_sets;

public:
	UnionFind(int N)
	{
		p.assign(N, 0), rank.assign(N, 0), set_size.assign(N, 1);
		for (int i = 0; i < N; i++) p[i] = i;
		num_sets = N;
	}

	int find_set(int i) { return p[i] == i ? i : (p[i] = find_set(p[i])); }

	// O(1)
	bool is_same_set(int i, int j) { return find_set(i) == find_set(j); }

	// O(1)
	void union_set(int i, int j)
	{
		if (!is_same_set(i, j))
		{
			num_sets -= 1;
			int a = find_set(i), b = find_set(j);
			if (rank[a] > rank[b])
			{
				p[b] = a;
				set_size[a] += set_size[b];
			}
			else
			{
				p[a] = b;
				set_size[b] += set_size[a];
				if (rank[a] == rank[b]) rank[b] += 1;
			}
		}
	}

	// O(1)
	int num_disjoint_sets() { return num_sets; }

	// O(1)
	int size_of_set(int i) { return set_size[find_set(i)]; }
};

// O(E log V), not going to implement Prim's algorithm.
int main()
{
	// Note, EDGE LIST is used, not ADJACENCY LIST. Format is weight, u, v;
	viii G = {
		Pair(4, Pair(0, 1)), Pair(2, Pair(1, 2)), Pair(4, Pair(0, 2)), Pair(6, Pair(0, 3)), 
		Pair(8, Pair(2, 3)), Pair(6, Pair(0, 4)), Pair(9, Pair(3, 4))
	};

	int N = 5, E = G.size();
	sort(G.begin(), G.end()); // Reverse for maximum spanning tree.
	UnionFind uf(N);
	int cost = 0;
	for (int i = 0; i < E; i++)
	{
		iii edge = G[i];
		if (!uf.is_same_set(edge.second.first, edge.second.second))
			cost += edge.first, uf.union_set(edge.second.first, edge.second.second);
	}
	cout << cost << endl;
}

// Minimum Spanning Subgraph
// Given some fixed edges on a graph, select the remaining edges to make the graph connected in the
// least expensive manner.
//
// Run Kruskal after said edges are fixed.

// Minimum Spanning Forest
// Find the least cost forest of K connected components.
//
// Run Kruskal as normal, but stop once the number of connected components has reached K.

// Second Best Spanning Tree
// Find the second best minimum spanning tree.
//
// Run Kruskal, then for each edge, mark it as unusable and try to recompute the MST. The best MST
// after this process is the second best overall.

// Minimax (and Maximin)
// Define the cost between u and v to be the maximum edge weight along the path. Among all of these
// paths, pick the one with the minimum max-edge-weight.
//
// The solution is the max edge weight between the two vertices on the MST.

