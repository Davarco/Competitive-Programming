#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int M, N, K;
vector<vector<int>> edges;
vector<bool> visited;
vector<bool> blacks;

int best_count;
vector<bool> best_blacks;

void search(int a, int count)
{
	bool flag = true; for (int i = 0; i < edges[a].size(); i++)
		if (blacks[edges[a][i]])
		{
			flag = false;
			break;
		}

	if (flag)
	{
		if (count+1 > best_count) 
		{
			best_count = count + 1;
			blacks[a] = true;
			best_blacks = blacks;
			blacks[a] = false;
		}
		visited[a] = true;
		for (int i = 0; i < edges[a].size(); i++)
		{
			int next = edges[a][i];
			if (!visited[next])
			{
				blacks[a] = true;
				search(next, count + 1);
				blacks[a] = false;
				search(next, count);
			}
		}
		visited[a] = false;
	}
	else
	{
		visited[a] = true;
		for (int i = 0; i < edges[a].size(); i++)
		{
			int next = edges[a][i];
			if (!visited[next])
				search(next, count);
		}
		visited[a] = false;
	}
}

int main()
{
	cin >> M;
	for (int m = 0; m < M; m++)
	{
		cin >> N >> K;
		edges.resize(N);
		visited.resize(N);
		blacks.resize(N);
		best_count = INT_MIN;
		for (int k = 0; k < K; k++)
		{
			int a, b; cin >> a >> b; a--; b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		search(0, 0);
		cout << best_count << endl;
		vector<int> temp;
		for (int i = 0; i < best_blacks.size(); i++) if (best_blacks[i]) temp.push_back(i+1);
		for (int i = 0; i < temp.size(); i++) 
			if (i != temp.size() - 1) cout << temp[i] << " "; 
			else cout << temp[i] << endl;
	}
}
