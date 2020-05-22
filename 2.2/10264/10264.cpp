#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <climits>

using namespace std;

typedef unsigned int uint;

int main()
{
	int N;
	while (scanf("%d\n", &N) != EOF)
	{
		int n = 1;
		for (int i = 0; i < N; i++)
			n *= 2;
		vector<int> weights(n);
		
		for (int i = 0; i < n; i++)
			scanf("%d\n", &weights[i]);

		vector<int> potencies(n, 0);
		for (uint i = 0; i < n; i++)
			for (uint j = 0; j < N; j++)
				potencies[i] += weights[i ^ (1 << j)];

		int best = INT_MIN;
		for (uint i = 0; i < n; i++)
		{
			for (uint j = 0; j < N; j++)
			{
				uint other = i ^ (1 << j);
				if (potencies[i] + potencies[other] > best)
					best = potencies[i] + potencies[other];
			}
		}
		cout << best << endl;
	}
}
