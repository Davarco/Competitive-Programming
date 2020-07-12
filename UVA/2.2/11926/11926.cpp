#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

#define END 1000000

int main()
{
	int N, M;
	while (scanf("%d %d\n", &N, &M) != EOF)
	{
		if (N == 0 && M == 0)
			break;

		bitset<END> calendar;
		bool flag = false;

		for (int i = 0; i < N; i++)
		{
			int start, end;
			cin >> start >> end;

			if (!flag)
			{
				for (int j = start; j < end; j++)
					if (calendar[j] != 1)
						calendar[j] = 1;
					else
						flag = true;
			}
		}

		for (int i = 0; i < M; i++)
		{
			int start, end, interval;
			cin >> start >> end >> interval;

			if (!flag)
			{
				while (start < END)
				{
					for (int j = start; j < min(end, END); j++)
						if (calendar[j] != 1)
							calendar[j] = 1;
						else
							flag = true;

					start += interval;
					end += interval;

					if (flag)
						break;
				}
			}
		}

		if (flag)
			cout << "CONFLICT" << endl;
		else
			cout << "NO CONFLICT" << endl;
	}
}
