#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;

// Given some N sets and a series of unions, find whether two sets are the same,
// the number of disjoint sets, and/or the size of each set.
class UnionFind
{
private:
	vector<int> p, rank, set_size;
	int num_sets;

public:
	UnionFind(int N)
	{
		p.assign(N, 0);
		rank.assign(N, 0);
		set_size.assign(N, 1);
		for (int i = 0; i < N; i++) p[i] = i;
		num_sets = N;
	}

	int find_set(int i)
	{
		return p[i] == i ? i : (p[i] = find_set(p[i]));
	}

	// O(1)
	bool is_same_set(int i, int j)
	{
		return find_set(i) == find_set(j);
	}

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
	int num_disjoint_sets()
	{
		return num_sets;
	}

	// O(1)
	int size_of_set(int i)
	{
		return set_size[find_set(i)];
	}
};

int main()
{
	int N, M;
	scanf("%d %d\n", &N, &M);
	UnionFind uf(N);
	
	char t0, t1, t2;
	scanf("%c%c%c\n", &t0, &t1, &t2);
	int a = t0 - 'A', b = t1 - 'A', c = t2 - 'A';
	
	vi m(26, -1);
	m[a] = 0;
	m[b] = 1;
	m[c] = 2;
	int index = 3;

	vector<vi> edges(N);

	for (int i = 0; i < M; i++)
	{
		scanf("%c%c\n", &t0, &t1);
		a = t0 - 'A';
		b = t1 - 'A';
		if (m[a] == -1)
		{
			m[a] = index;
			index += 1;
		}
		if (m[b] == -1)
		{
			m[b] = index;
			index += 1;
		}

		if (m[a] < m[b])
			edges[m[a]].push_back(m[b]);
		else
			edges[m[b]].push_back(m[a]);
	}

	int count = 0;
	int prev = 0;
	while (flag)
	{
		for (int i = 0; i < edges.size(); i++)
		{
			for (int j = 0; j < edges[i].size(); j++)
			{
				edges[i][j]	
			}
		}
	}
}




