#include <iostream>
#include <vector>

using namespace std;

typedef vector<pair<int, int>> vii;
typedef vector<int> vi;

int main()
{
	int N, M;
	while (scanf("%d %d\n", &N, &M) != EOF)
	{
		vector<vi> occurrences(1000001);
		for (int i = 0; i < N; i++)
		{
			int number;
			cin >> number;
			occurrences[number].push_back(i+1);
		}
		for (int i = 0; i < M; i++)
		{
			int k, v;
			cin >> k >> v;
			if (k > occurrences[v].size())
				cout << 0 << endl;
			else
				cout << occurrences[v][k-1] << endl;
		}
	}
}
