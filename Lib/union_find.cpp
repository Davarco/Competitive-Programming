// Modified from Competitive Programming 3.
#include <iostream>
#include <vector>

using namespace std;

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
		for (int i = 0; i < N; i++)
			p[i] = i;
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
				if (rank[a] == rank[b])
					rank[b] += 1;
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
	UnionFind uf(5);
	uf.union_set(0, 1);
	cout << uf.num_disjoint_sets() << " " << uf.is_same_set(0, 1) << " " << uf.size_of_set(0) << endl;
}

