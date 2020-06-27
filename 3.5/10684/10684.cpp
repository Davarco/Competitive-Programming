#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main()
{
	while (cin >> N)
	{
		if (N == 0) break;

		vector<int> seq(N);
		for (int n = 0; n < N; n++) cin >> seq[n];

		int sum = 0, ans = 0;
		for (int i = 0; i < N; i++)
		{
			sum += seq[i];
			if (sum > ans) ans = sum;
			if (sum < 0) sum = 0;
		}

		if (ans != 0)
			printf("The maximum winning streak is %d.\n", ans);
		else
			printf("Losing streak.\n");
	}
}

