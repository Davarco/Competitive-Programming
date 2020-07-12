#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;
typedef vector<vector<int>> vvi;

int N; vector<int> bags;

int main()
{
	bool flag = true;
	while (cin >> N)
	{
		if (N == 0) break;
		if (flag) flag = false;
		else cout << endl;

		bags.assign(N, 0);
		for (int n = 0; n < N; n++) cin >> bags[n];
		sort(bags.begin(), bags.end());	
		int count = 0, prev = -1, highest = INT_MIN;
		for (int i = 0; i < N; i++) 
		{
			if (bags[i] == prev) count += 1;
			else { prev = bags[i]; count = 1; }
			if (count > highest) highest = count;
		}
		vvi output(highest, vector<int>());
		cout << highest << endl;
		for (int i = 0; i < N; i++)
			output[i % highest].push_back(bags[i]);
		for (int i = 0; i < highest; i++)
			for (int j = 0; j < output[i].size(); j++)
				if (j == output[i].size() - 1) cout << output[i][j] << endl;
				else cout << output[i][j] << " ";
	}
}
