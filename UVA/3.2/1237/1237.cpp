#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int D; cin >> D;
		vector<pair<int, int>> prices;
		vector<string> makers;
		for (int d = 0; d < D; d++)
		{
			string M; int L, H; cin >> M >> L >> H;
			makers.push_back(M);
			prices.push_back(make_pair(L, H));
		}

		int Q; cin >> Q;
		for (int q = 0; q < Q; q++)
		{
			int P; cin >> P;
			int count = 0; string maker = "";
			for (int i = 0; i < D; i++)
			{
				if (P >= prices[i].first && P <= prices[i].second)
				{
					count += 1;
					maker = makers[i];
				}
			}
			if (count == 1)
				cout << maker << endl;
			else
				cout << "UNDETERMINED" << endl;
		}
		if (t != T-1)
			cout << endl;
	}
}
