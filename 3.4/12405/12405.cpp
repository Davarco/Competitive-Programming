#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
string field;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> field;
		int count = 0, end = -1;
		for (int i = 0; i < N; i++)
		{
			if (field[i] == '.' && end < i)
			{
				end = i + 2;
				count += 1;
			}
		}
		printf("Case %d: %d\n", t+1, count);
	}
}

