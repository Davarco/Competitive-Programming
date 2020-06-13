#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int K;
	while (cin >> K)
	{
		// 1/k = 1/x + 1/y
		// xy = yk + xk
		// x = yk / (y - k)
		int end = K * 2;
		int Y_start = K + 1;

		vector<pair<int, int>> pairs;
		for (int Y = Y_start; Y <= end; Y++)
		{
			int X = Y * K / (Y - K);
			if (X*Y == Y*K + X*K)
				pairs.push_back(make_pair(X, Y));
		}
		cout << pairs.size() << endl;
		for (int i = 0; i < pairs.size(); i++)
			printf("1/%d = 1/%d + 1/%d\n", K, pairs[i].first, pairs[i].second);
	}
}
