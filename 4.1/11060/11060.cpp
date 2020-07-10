#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

int N, M;
string drinks[100];
unordered_map<string, int> um;
set<int> abv[100];

int main()
{
	int T = 0;
	while (cin >> N)
	{
		for (int n = 0; n < N; n++) cin >> drinks[n], um[drinks[n]] = n;
		cin >> M; 
		for (int n = 0; n < N; n++) abv[n].clear();
		for (int m = 0; m < M; m++)
		{
			string a, b;
			cin >> a >> b;
			abv[um[b]].insert(um[a]);
		}

		vector<int> topo;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int n = 0; n < N; n++)
			if (abv[n].size() == 0)
				pq.push(n);
		while (pq.size() > 0) 
		{
			int v = pq.top(); pq.pop();
			topo.push_back(v);
			for (int n = 0; n < N; n++)
				if (abv[n].count(v) > 0)
				{
					abv[n].erase(v);
					if (abv[n].size() == 0) pq.push(n);
				}
		}

		printf("Case #%d: Dilbert should drink beverages in this order:", ++T);
		for (int i = 0; i < topo.size(); i++)
			printf(" %s", drinks[topo[i]].c_str());
		printf(".\n\n");
	}
}
