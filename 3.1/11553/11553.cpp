#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N; cin >> N;
		vector<vector<int>> M(N, vector<int>(N)); 
		for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) cin >> M[r][c];

		vector<int> order(N); for (int n = 0; n < N; n++) order[n] = n;
		int best_sum = INT_MAX;
		do {
			int sum = 0;
			for (int i = 0; i < N; i++)
				sum += M[i][order[i]];
			if (sum < best_sum) best_sum = sum;
		}
		while (next_permutation(order.begin(), order.end()));
		cout << best_sum << endl;
	}
}
