#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		map<int, int> occurrences;
		
		int begin=1, best=0;
		for (int i = 1; i <= N; i++)
		{
			int id;
			cin >> id;
			if (occurrences[id] >= begin) 
				begin = occurrences[id] + 1;
			int current = i - begin + 1;
			best = current > best ? current : best;
			occurrences[id] = i;
		}
		cout << best << endl;
	}
}
