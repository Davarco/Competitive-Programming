#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N; cin >> N;
		vector<int> A(N);
		for (int n = 0; n < N; n++) cin >> A[n];

		int count = 0;
		for (int i = 1; i < N; i++)
			for (int j = 0; j < i; j++)
				if (A[j] <= A[i]) count += 1;
		cout << count << endl;
	}
}
