#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef pair<int, int> ii;
typedef vector<pair<int, ii>> viii;

#define Pair(a, b) make_pair(a, b)

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

int M, N, orig_cost;
viii G;

int main()
{
	while (cin >> M >> N)
	{
		if (M == 0 && N == 0)
			break;
		G.clear(), orig_cost = 0;
		for (int n = 0; n < N; n++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			G.push_back(Pair(c, Pair(a, b)));	
			orig_cost += c;
		}

		sort(G.begin(), G.end());
		int cost = 0;
		UnionFind uf(M);
		for (int i = 0; i < N; i++)
		{
			pair<int, ii> edge = G[i];
			if (!uf.is_same_set(edge.second.first, edge.second.second))
				cost += edge.first, uf.union_set(edge.second.first, edge.second.second);
		}
		cout << orig_cost - cost << endl;
	}
}
