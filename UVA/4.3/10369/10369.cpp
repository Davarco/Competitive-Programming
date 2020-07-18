#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef vector<pair<double, ii>> vdii;

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

int cmp(pair<double, ii> a, pair<double, ii> b)
{
	return a.first > b.first;
}

int N, S, P;

int main()
{
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		cin >> S >> P;
		vdd pairs(P);
		for (int p = 0; p < P; p++)
		{
			double X, Y;
			cin >> X >> Y;
			pairs[p] = Pair(X, Y);
		}
		vdii edges;
		for (int a = 0; a < P; a++)
			for (int b = 0; b < a; b++)
			{
				double X = pairs[a].first - pairs[b].first, Y = pairs[a].second - pairs[b].second;
				edges.push_back(Pair(sqrt(X*X+Y*Y), Pair(a, b)));
			}

		sort(edges.begin(), edges.end());
		UnionFind uf(P);
		int e = 0, cc = 0;
		for (; e < edges.size() && cc != P-S; e++)
		{
			pair<double, ii> edge = edges[e];
			if (!uf.is_same_set(edge.second.first, edge.second.second))
				uf.union_set(edge.second.first, edge.second.second), cc += 1;
		}
		printf("%.02lf\n", edges[e-1].first);
	}
}
