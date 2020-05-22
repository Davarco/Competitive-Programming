#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int N;
	while (scanf("%d\n", &N) != EOF)
	{
		if (N == 0)
			break;
		
		map<vector<int>, int> counts;
		int best = 0;
		for (int i = 0; i < N; i++)
		{
			vector<int> courses(5);
			cin >> courses[0] >> courses[1] >> courses[2] >> courses[3] >> courses[4];
			sort(courses.begin(), courses.end());
			counts[courses] += 1;
			best = counts[courses] > best ? counts[courses] : best;
		}

		int total = 0;
		for (auto it = counts.begin(); it != counts.end(); it++)
			if (it->second == best)
				total += 1;
		cout << total*best << endl;
	}
}
