#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
vector<int> rungs;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N; 
		rungs.assign(N, 0); 
		for (int n = 0; n < N; n++) cin >> rungs[n];

		int a = 0, b = *max_element(rungs.begin(), rungs.end()) + N;
		int now = 0;
		while (a < b)
		{
			int k = (a+b)/2, temp_k = k;
			int i = 0;
			while (i < N && rungs[i] - rungs[i-1] <= temp_k)
			{
				if (rungs[i] - rungs[i-1] == temp_k)
					temp_k -= 1;
				i += 1;
			}

			if (i == N)
				b = k;
			else
				a = k + 1;
		}
		printf("Case %d: %d\n", t+1, a);
	}
}
