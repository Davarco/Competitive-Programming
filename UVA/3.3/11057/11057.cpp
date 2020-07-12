#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> prices;

int main()
{
	bool flag = true;
	while (cin >> N)
	{
		prices.assign(N, 0); for (int n = 0; n < N; n++) cin >> prices[n];
		sort(prices.begin(), prices.end());
		cin >> M;

		int a = 0, b = N-1;
		int best_a = -1, best_b = -1;
		while (a < b)
		{
			if (prices[a] + prices[b] == M)
			{
				best_a = a;
				best_b = b;
			}
			if (prices[a] + prices[b] > M)
				b -= 1;
			else
				a += 1;
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", prices[best_a], prices[best_b]);
	}
}
