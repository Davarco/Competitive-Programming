#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int K;
	bool flag = true;
	while (cin >> K)
	{
		if (K == 0) break;
		if (flag)
			flag = false;
		else
			cout << endl;

		vector<int> S(K);
		for (int k = 0; k < K; k++) cin >> S[k];

		for (int a = 0; a < K; a++)
			for (int b = a+1; b < K; b++)
				for (int c = b+1; c < K; c++)
					for (int d = c+1; d < K; d++)
						for (int e = d+1; e < K; e++)
							for (int f = e+1; f < K; f++)
								printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
	}
}
