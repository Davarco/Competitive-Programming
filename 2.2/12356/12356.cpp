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

		std::vector<int> next(S+1);
		std::vector<int> prev(S+1);
		for (int i = 1; i <= S; i++)
		{
			next[i] = i+1;
			prev[i] = i-1;
		}
		next[S] = 0;
	
		for (int i = 0; i < B; i++) 
		{
			bool flag;
			int L, R;
			std::cin >> L >> R;

			next[prev[L]] = next[R];
			prev[next[R]] = prev[L];
			if (prev[L] == 0 && next[R] == 0)
				printf("* *\n");
			else if (prev[L] == 0) 
				printf("* %d\n", next[R]);
			else if (next[R] == 0)
				printf("%d *\n", prev[L]);
			else
				printf("%d %d\n", prev[L], next[R]);
		}
		printf("-\n");
	}
}
