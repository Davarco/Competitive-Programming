#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, D;

int main()
{
	scanf("%d\n", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%d %d\n", &N, &D);
		vector<int> LR;
		vector<int> RL;
		LR.push_back(0); RL.push_back(0);

		int index = 0;
		for (int n = 0; n < N; n++)
		{
			char c; int a;
			if (n == N-1) scanf("%c-%d\n", &c, &a);
			else scanf("%c-%d ", &c, &a);
			if (c == 'B')
			{
				LR.push_back(a);
				RL.push_back(a);
				index = 0;
			}
			else
			{
				if (index % 2 == 0) LR.push_back(a);
				else RL.push_back(a);
				index += 1;
			}
		}
		LR.push_back(D); RL.push_back(D);

		int highest = 0;
		for (int i = 0; i < LR.size()-1; i++)
			if (LR[i+1] - LR[i] > highest) 
				highest = LR[i+1] - LR[i];
		for (int i = 0; i < RL.size()-1; i++)
			if (RL[i+1] - RL[i] > highest) 
				highest = RL[i+1] - RL[i];
		printf("Case %d: %d\n", t+1, highest);
	}
}
