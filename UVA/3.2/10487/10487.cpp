#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int main()
{
	int N;
	int C = 1;
	while (cin >> N)
	{
		if (N == 0) break;
		printf("Case %d:\n", C++);

		vector<int> seq(N);
		for (int i = 0; i < N; i++) cin >> seq[i];

		// sort(seq.begin(), seq.end());
		int M; cin >> M;
		for (int m = 0; m < M; m++)
		{
			int Q; cin >> Q;
			int sum;
			bool flag = false;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < i; j++)
					if (!flag || abs(seq[i]+seq[j]-Q) < abs(sum-Q)) 
					{
						flag = true;
						sum = seq[i] + seq[j];
					}
			printf("Closest sum to %d is %d.\n", Q, sum);
		}
	}
}
