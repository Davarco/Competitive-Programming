#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <climits>
#include <cmath>

using namespace std;
#define INF 1000000000

int N; int END;
double A[8], B[8];
int sequence[8];
int best_sequence[8];
double best_sofar;

void tsp(int i, int mask, double sofar, int idx)
{
	if (mask == END)
	{
		if (sofar < best_sofar)
		{
			best_sofar = sofar;
			for (int n = 0; n < N; n++)
				best_sequence[n] = sequence[n];
		}
	}
	else
	{
		for (int n = 0; n < N; n++)
		{
			if ((mask & (1 << n)) == 0)
			{
				double dist = sqrt((A[n]-A[i])*(A[n]-A[i])+(B[n]-B[i])*(B[n]-B[i])) + 16;
				sequence[idx] = n;
				tsp(n, mask | (1 << n), sofar + dist, idx+1);
			}
		}
	}
}

int main()
{
	int T = 0;
	while (cin >> N)
	{
		if (N == 0) break;
		END = 1; for (int n = 0; n < N; n++) END *= 2; END -= 1;
		for (int n = 0; n < N; n++) cin >> A[n] >> B[n];

		best_sofar = INF;
		int best_idx = -1; double best_v = INF;
		for (int n = 0; n < N; n++)
		{
			sequence[0] = n;
			tsp(n, 1 << n, 0, 1);
			if (best_sofar < best_v)
			{
				best_v = best_sofar;
				best_idx = n;
			}
		}
		printf("**********************************************************\n");
		printf("Network #%d\n", ++T);
		for (int n = 0; n < N-1; n++)
		{
			int a0 = A[best_sequence[n]], b0 = B[best_sequence[n]];
			int a1 = A[best_sequence[n+1]], b1 = B[best_sequence[n+1]];
			double dist = sqrt((a0-a1)*(a0-a1)+(b0-b1)*(b0-b1)) + 16;
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", a0, b0, a1, b1, dist);
		}
		printf("Number of feet of cable required is %.2lf.\n", best_sofar);
	}
}
