#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, string> is;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<is> vis;

#define INF 100000000

int M;

int main()
{
	while (cin >> M)
	{
		if (M == 0)
			break;

		int Lid = 0;
		unordered_map<string, int> Lmap;
		unordered_map<int, string> Linv;

		string o, D; 
		cin >> o >> D;

		vector<pair<int, pair<string, int>>> edges[4000];
		for (int m = 0; m < M; m++)
		{
			string i1, i2, p; 
			cin >> i1 >> i2 >> p;
			if (Lmap.find(i1) == Lmap.end())
				Linv[Lid] = i1, Lmap[i1] = Lid++;
			if (Lmap.find(i2) == Lmap.end())
				Linv[Lid] = i2, Lmap[i2] = Lid++;
			edges[Lmap[i1]].push_back(make_pair(Lmap[i2], make_pair(p, false)));
			edges[Lmap[i2]].push_back(make_pair(Lmap[i1], make_pair(p, false)));
		}
		if (Lmap.find(o) == Lmap.end() || Lmap.find(D) == Lmap.end())
		{
			cout << "impossivel" << endl;
			continue;
		}

		priority_queue<pair<pair<int, char>, int>> pq;
		pq.push(make_pair(make_pair(0, '!'), Lmap[o]));
		int found = false;
		while (pq.size() > 0)
		{
			pair<pair<int, char>, int> front = pq.top(); pq.pop(); 
			int d = front.first.first, u = front.second; char p = front.first.second;
			if (u == Lmap[D])
			{
				cout << -d << endl;
				found = true;
				break;
			}
			for (int i = 0; i < edges[u].size(); i++)
			{
				if (!edges[u][i].second.second && edges[u][i].second.first[0] != p)
				{
					pq.push(make_pair(make_pair(d-edges[u][i].second.first.size(), edges[u][i].second.first[0]), edges[u][i].first));
					edges[u][i].second.second = true;
				}
			}
		}
		if (!found)
			cout << "impossivel" << endl;
	}
}
