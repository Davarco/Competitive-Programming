#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef vector<pair<int, int>> vii;

int main()
{
	int N, M;
	while (scanf("%d %d\n", &N, &M) != EOF)
	{
		vector<vii> edges(N);
		for (int r = 0; r < N; r++)
		{
			int C;
			cin >> C;
			edges[r].assign(C, make_pair(0, 0));
			for (int c = 0; c < C; c++)
			{
				int temp;
				cin >> temp;
				edges[r][c].first = temp;
			}
			for (int c = 0; c < C; c++)
			{
				int temp; 
				cin >> temp;
				edges[r][c].second = temp;
			}
		}

		cout << M << " " << N << endl;
		for (int c = 0; c < M; c++)
		{
			vii temp;
			for (int r0 = 0; r0 < N; r0++)
				for (int c0 = 0; c0 < edges[r0].size(); c0++)
					if (edges[r0][c0].first == c+1)
						temp.push_back(make_pair(r0+1, edges[r0][c0].second));
			cout << temp.size();
			if (temp.size() != 0) cout << " ";
			for (int i = 0; i < temp.size(); i++)
			{
				cout << temp[i].first;
				if (i != temp.size()-1) cout << " ";
			}
			cout << endl;
			for (int i = 0; i < temp.size(); i++)
			{
				cout << temp[i].second;
				if (i != temp.size()-1) cout << " ";
			}
			cout << endl;
		}
	}
}
