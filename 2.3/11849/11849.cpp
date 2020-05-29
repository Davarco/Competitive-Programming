#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int N, M;
	while (scanf("%d %d\n", &N, &M) != EOF)
	{
		if (N == 0 && M == 0)
			break;
		set<int> copies;
		int total = 0;
		for (int i = 0; i < N; i++)
		{
			int cd;
			cin >> cd;
			if (copies.count(cd) > 0)
				total += 1;
			copies.insert(cd);
		}
		for (int i = 0; i < M; i++)
		{
			int cd;
			cin >> cd;
			if (copies.count(cd) > 0)
				total += 1;
			copies.insert(cd);
		}
		cout << total << endl;
	}
}
