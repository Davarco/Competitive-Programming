#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

typedef long long LL;

LL N, Q, D, M;
vector<LL> numbers;
LL knapsack[200][20][10];

int search(LL index, LL sum, LL remaining)
{
	if (remaining == 0 && sum % D == 0)
		return 1;
	else if (remaining == 0 || index == N)
		return 0;
	if (knapsack[index][sum][remaining] == -1)
	{
		int next = (sum+numbers[index]) % D;
		if (next < 0) next += D;
		int a = search(index+1, next, remaining-1);
		int b = search(index+1, sum, remaining);
		knapsack[index][sum][remaining] = a + b;
		// return a + b;
	}
	return knapsack[index][sum][remaining];
}

int main()
{
	int T = 0;
	while (cin >> N >> Q)
	{
		if (N == 0 && Q == 0) break;
		printf("SET %d:\n", ++T);
		numbers.assign(N, 0); for (int n = 0; n < N; n++) cin >> numbers[n];
		
		for (int q = 0; q < Q; q++)
		{
			cin >> D >> M;
			memset(knapsack, -1, sizeof(knapsack));
			int count = search(0, 0, M);
			printf("QUERY %d: %d\n", q+1, count);
		}
	}
}
