#include <iostream>


int main()
{
	while (true)
	{
		int S, P;
		scanf("%d %d\n", &S, &P);
		if (S == 0 && P == 0)
			break;

		int r = S/2+1;
		int c = S/2+1;

		int dx = 1;
		bool change_row = true;
		while (P > 1)
		{
			if (change_row)
				if (abs(P-1) < abs(dx))
					r += (P-1)*dx/abs(dx);
				else
					r += dx;
			else
				if (abs(P-1) < abs(dx))
					c -= (P-1)*dx/abs(dx);
				else
					c -= dx;

			P -= abs(dx);

			if (change_row)
				change_row = false;
			else
			{
				if (dx < 0)
					dx -= 1;
				else
					dx += 1;
				dx *= -1;
				change_row = true;
			}
		}
		printf("Line = %d, column = %d.\n", r, c);
	}
}
