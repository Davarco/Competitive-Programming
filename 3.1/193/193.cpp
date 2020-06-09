#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>

using namespace std;

int M, N, K;
vector<vector<bool>> edges;
vector<bool> visited;
vector<bool> blacks;

int best_count;
vector<int> best_vec;

bool no_neighbors(int i)
{
	for (int j = 0; j < N; j++)
		if (visited[j] && edges[i][j])
			return false;
	return true;
}

void search(int a)
{
	if (a > best_count) 
	{
		best_vec.clear();
		for (int i = 0; i < N; i++)
			if (visited[i]) best_vec.push_back(i+1);
		best_count = a;
	}
	if (a == N) return;
	for (int i = 0; i < N; i++)
	{
		if (!visited[i] && no_neighbors(i))
		{
			visited[i] = true;
			search(a+1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> M;
	for (int m = 0; m < M; m++)
	{
		cin >> N >> K;
		edges.assign(N, vector<bool>(N, false));
		visited.assign(N, false);
		blacks.assign(N, false);
		best_count = INT_MIN;
		for (int k = 0; k < K; k++)
		{
			int a, b; cin >> a >> b; a--; b--;
			edges[a][b] = true;
			edges[b][a] = true;
		}
		search(0);
		cout << best_count << endl;
		for (int i = 0; i < best_vec.size()-1; i++)
			cout << best_vec[i] << " ";
		cout << best_vec[best_vec.size()-1] << endl;
	}
}
