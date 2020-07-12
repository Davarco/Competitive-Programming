#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int N, T;

int best; vector<int> best_vec;

void find(const vector<int> &durations, int min, int sum, const vector<int> &current)
{
	for (int i = min; i < T; i++)
	{
		vector<int> next = current; next.push_back(durations[i]);
		if (best == -1 || (sum + durations[i] <= N && abs(N-sum-durations[i]) < abs(N-best)))
		{
			best = sum + durations[i];
			best_vec = next;
		}
		// for (int i = 0; i < next.size(); i++) cout << next[i] << " "; cout << endl;
		find(durations, i+1, sum+durations[i], next);
	}
}

int main()
{
	while (cin >> N >> T)
	{
		vector<int> durations(T);
		for (int t = 0; t < T; t++) cin >> durations[t];
		best = -1;
		find(durations, 0, 0, {});
		for (int i = 0; i < best_vec.size(); i++) cout << best_vec[i] << " "; printf("sum:%d\n", best);
	}
}
