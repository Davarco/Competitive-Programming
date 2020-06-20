#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N; vector<int> C;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N; 
		C.assign(N, 0); for (int n = 0; n < N; n++) cin >> C[n];

		int now = 0;
		int kinds = 0;
		for (int i = 0; i < N-1; i++)
		{
			if (now + C[i] < C[i+1])
			{
				now += C[i];
				kinds += 1;
			}
		}
		kinds += 1;
		cout << kinds << endl;
	}
}
