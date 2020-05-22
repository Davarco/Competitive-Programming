#include <iostream>
#include <vector>


int main()
{
	while (true)
	{
		int S, B;
		scanf("%d %d\n", &S, &B);

		if (S == 0 && B == 0)
			break;

		std::vector<bool> soldiers(S, true);
		for (int i = 0; i < B; i++) 
		{
			bool flag;
			int L, R;
			std::cin >> L >> R;
			for (int j = L-1; j < R; j++)
				soldiers[j] = false;

			int maxL = -1;
			for (int j = L-1; j >= 0; j--)
			{
				if (soldiers[j])
				{
					maxL = j;
					break;
				}
			}

			int minR = -1;
			for (int j = R; j < S; j++)
			{
				if (soldiers[j])
				{
					minR = j;
					break;
				}
			}

			if (maxL == -1 && minR == -1)
				printf("* *\n");
			else if (maxL == -1) 
				printf("* %d\n", minR+1);
			else if (minR == -1)
				printf("%d *\n", maxL+1);
			else
				printf("%d %d\n", maxL+1, minR+1);
		}
		printf("-\n");
	}
}
