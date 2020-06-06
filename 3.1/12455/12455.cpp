#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, P; cin >> N >> P;
		vector<int> bars(P); for (int p = 0; p < P; p++) cin >> bars[p];
		bool flag = false;
		for (int i = 0; i < (1 << P); i++)
		{
			int sum = 0;
			for (int b = 0; b < P; b++) if ((i >> b) & 1) sum += bars[b];
			if (sum == N) 
			{
				cout << "YES" << endl;
				flag = true;
				break;
			}
		}
		if (!flag) cout << "NO" << endl;
	}
}
