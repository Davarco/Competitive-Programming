#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> viii;
typedef vector<vii> vvii;

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

int T, N, M;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		viii edges(M);
		for (int m = 0; m < M; m++)
		{
			int a, b, c; 
			cin >> a >> b >> c; a--, b--;
			edges[m] = Pair(c, Pair(a, b));
		}

		sort(edges.begin(), edges.end());

		vi chosen;
		UnionFind uf0(N);
		int cost0 = 0;
		for (int m = 0; m < M; m++)
		{
			pair<int, ii> edge = edges[m];
			if (!uf0.is_same_set(edge.second.first, edge.second.second))
				chosen.push_back(m), cost0 += edge.first, uf0.union_set(edge.second.first, edge.second.second);
		}
		printf("%d ", cost0);
	
		int best_cost1 = INT_MAX;
		for (int i = 0; i < chosen.size(); i++)
		{
			UnionFind uf1(N);
			int cost1 = 0, cc = N;
			for (int m = 0; m < M; m++)
			{
				if (chosen[i] == m)
					continue;
				pair<int, ii> edge = edges[m];
				if (!uf1.is_same_set(edge.second.first, edge.second.second))
					cc -= 1, cost1 += edge.first, uf1.union_set(edge.second.first, edge.second.second);
			}
			if (cc == 1)
				best_cost1 = min(best_cost1, cost1);
		}
		printf("%d\n", best_cost1);
	}
}
