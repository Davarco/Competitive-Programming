#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
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

int N, M;
viii G;

int main()
{
	while (cin >> N >> M)
	{
		if (N == 0 && M == 0)
			break;
		G.clear();
		for (int m = 0; m < M; m++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			G.push_back(Pair(w, Pair(u, v)));
		}

		sort(G.begin(), G.end());
		vi vis(M, false);
		UnionFind uf(N);
		for (int m = 0; m < M; m++)
		{
			pair<int, ii> edge = G[m];
			if (!uf.is_same_set(edge.second.first, edge.second.second))
			{
				uf.union_set(edge.second.first, edge.second.second);
				vis[m] = true;
			}
		}
		vi H; 
		for (int m = 0; m < M; m++) if (!vis[m]) H.push_back(G[m].first);
		sort(H.begin(), H.end());
		for (int i = 0; i < H.size(); i++)
			if (i != H.size()-1)
				cout << H[i] << " ";
			else 
				cout << H[i] << endl;
		if (H.size() == 0)
			cout << "forest" << endl;
	}
}
