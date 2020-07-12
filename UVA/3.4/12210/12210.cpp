#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int B, S;
vector<int> bachelors, spinsters;

int main()
{
	int C = 0;
	while (cin >> B >> S)
	{
		if (B == 0 && S == 0) break;
		bachelors.assign(B, 0); spinsters.assign(S, 0);
		for (int b = 0; b < B; b++) cin >> bachelors[b];
		for (int s = 0; s < S; s++) cin >> spinsters[s];
		sort(bachelors.begin(), bachelors.end());
		sort(spinsters.begin(), spinsters.end());

		if (B <= S)
			printf("Case %d: %d\n", ++C, 0);
		else
			printf("Case %d: %d %d\n", ++C, B-S, bachelors[0]);
	}
}
