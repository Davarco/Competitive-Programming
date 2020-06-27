#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> sequence;

int main()
{
	int next;
	while (cin >> next) sequence.push_back(next); 
	N = sequence.size();

	vector<int> distance(N);
	vector<int> previous(N);
	distance[0] = 1;
	previous[0] = -1;

	int gbest = 0;
	for (int i = 1; i < N; i++)
	{
		int best = -1;
		for (int j = 0; j < i; j++)
			if (sequence[i] > sequence[j] && distance[j] >= distance[best])
				best = j;
		if (best != -1)
		{
			distance[i] = distance[best]+1;
			previous[i] = best;
		}
		else
		{
			distance[i] = 1;
			previous[i] = -1;
		}
		if (distance[i] >= distance[gbest])
			gbest = i;
	}
	int a = gbest;
	cout << distance[gbest] << endl << "-" << endl;
	vector<int> reversed(distance[gbest]);
	reversed[distance[gbest]-1] = sequence[a];
	for (int i = 1; i < distance[gbest]; i++)
	{
		a = previous[a];
		reversed[distance[gbest]-i-1] = sequence[a];
	}
	for (int i = 0; i < reversed.size(); i++)
		cout << reversed[i] << endl;
}
