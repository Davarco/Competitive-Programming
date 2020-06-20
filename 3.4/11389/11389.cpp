#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, D, R;
vector<int> morning, evening;

int main()
{
	while (cin >> N >> D >> R)
	{
		if (N == 0 && D == 0 && R == 0) break;

		morning.assign(N, 0); evening.assign(N, 0);
		for (int n = 0; n < N; n++) cin >> morning[n];
		for (int n = 0; n < N; n++) cin >> evening[n];

		sort(morning.begin(), morning.end());
		sort(evening.begin(), evening.end());
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			int next = morning[i] + evening[N-i-1];
			sum += max(next - D, 0);
		}
		cout << sum * R << endl;
	}
}
