#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;

int N;
vi edges[200];

int main()
{
	scanf("%d\n\n", &N);
	for (int n = 0; n < N; n++)
	{
		if (n != 0)
			cout << endl;
		vector<string> words;
		unordered_map<string, int> wordmap;
		for (int i = 0; i < 200; i++)
			edges[i].clear();

		int W = 0;
		string in;
		while (getline(cin, in) && in != "*")
		{
			wordmap[in] = W++, words.push_back(in);
		}
		for (int a = 0; a < W; a++)
			for (int b = 0; b < a; b++)
				if (words[a].size() == words[b].size())
				{
					int diff = 0;
					for (int i = 0; i < words[a].size(); i++)
						if (words[a][i] != words[b][i])
							diff += 1;
					if (diff == 1)
						edges[a].push_back(b), edges[b].push_back(a);
				}

		while (getline(cin, in) && in != "")
		{
			stringstream ss(in);
			string a, b;
			ss >> a >> b;

			int start = wordmap[a], end = wordmap[b];
			vi distance(W, -1);
			queue<int> q;
			q.push(start), distance[start] = 0;
			while (q.size() > 0)
			{
				int u = q.front(); q.pop();
				for (int i = 0; i < edges[u].size(); i++)
				{
					int v = edges[u][i];
					if (distance[v] == -1)
					{
						distance[v] = distance[u] + 1;
						q.push(v);
					}
				}
			}
			cout << a << " " << b << " " << distance[end] << endl;
		}
	}
}
