#include <iostream>
#include <algorithm>
#include <vector>

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

int C, S, Q;
viii edges;
int A, B;
vi vis;

int dfs(const vvii &G, int u)
{
	if (u == B)
		return 0;
	vis[u] = true;
	for (int i = 0; i < G[u].size(); i++)
	{
		ii v = G[u][i];
		if (!vis[v.first])
		{
			int ans = dfs(G, v.first);
			if (ans != -1)
				return max(v.second, ans);
		}
	}
	return -1;
}

int main()
{
	int T = 0;
	while (cin >> C >> S >> Q)
	{
		if (C == 0 && S == 0 && Q == 0)
			break;

		if (T != 0)	printf("\n"); printf("Case #%d\n", ++T);

		edges.clear();
		for (int s = 0; s < S; s++)
		{
			int a, b, c;
			cin >> a >> b >> c; a--, b--;
			edges.push_back(Pair(c, Pair(a, b)));
		}

		sort(edges.begin(), edges.end());
		UnionFind uf(C);
		vvii G(C);
		for (int s = 0; s < S; s++)
		{
			pair<int, ii> edge = edges[s];
			int a = edge.second.first, b = edge.second.second, c = edge.first;
			if (!uf.is_same_set(a, b))
				G[a].push_back(Pair(b, c)), G[b].push_back(Pair(a, c)), uf.union_set(a, b);
		}

		for (int q = 0; q < Q; q++)
		{
			cin >> A >> B; A--, B--;
			vis.assign(C, false);
			int ans = dfs(G, A);
			if (ans == -1)
				printf("no path\n");
			else
				printf("%d\n", ans);
		}
	}
}



