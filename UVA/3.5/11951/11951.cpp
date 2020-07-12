#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

typedef long long LL;

int T, N, M, K;
LL district[100][100];

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M >> K;				
		for (int r = 0; r < N; r++) for (int c = 0; c < M; c++)
		{
			cin >> district[r][c];
			if (r > 0) district[r][c] += district[r-1][c];
			if (c > 0) district[r][c] += district[r][c-1];
			if (r > 0 && c > 0) district[r][c] -= district[r-1][c-1];
		}

		LL area = LLONG_MIN, price = LLONG_MAX;
		for (int r0 = 0; r0 < N; r0++) for (int c0 = 0; c0 < M; c0++)
			for (int r1 = r0; r1 < N; r1++) for (int c1 = c0; c1 < M; c1++)
			{
				LL subarea = (r1-r0+1)*(c1-c0+1);
				LL subprice = district[r1][c1];
				if (r0 > 0) subprice -= district[r0-1][c1];
				if (c0 > 0) subprice -= district[r1][c0-1];
				if (r0 > 0 && c0 > 0) subprice += district[r0-1][c0-1];

				if (subprice <= K)
				{
					if (subarea > area)
					{
						area = subarea;
						price = subprice;
					}
					else if (subarea == area && subprice < price)
					{
						area = subarea;
						price = subprice;
					}
				}
			}
		if (area == LLONG_MIN && price == LLONG_MAX)
		{
			area = 0;
			price = 0;
		}
		printf("Case #%d: %lld %lld\n", t+1, area, price);
	}
}
