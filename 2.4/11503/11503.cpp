#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

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
	int N;
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		UnionFind uf(200000);
		unordered_map<string, int> m;
		int index = 0;

		int F;
		cin >> F;
		for (int i = 0; i < F; i++)
		{
			string first, second;
			cin >> first >> second;
			if (m.find(first) == m.end())
				m[first] = index++;
			if (m.find(second) == m.end())
				m[second] = index++;
			int a = m[first];
			int b = m[second];
			uf.union_set(a, b);
			cout << uf.size_of_set(a) << endl;
		}
	}
}
