#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;
typedef vector<LL> vi;

int N;
vi denom({ 1, 5, 10, 25, 50 });
LL dp[5][30001];

LL coins(int id, LL sum)
{
	if (sum == N)
		return 1;
	if (id == 5)
		return 0;
	if (dp[id][sum] == -1)
	{
		LL a = coins(id+1, sum);
		LL b = sum+denom[id] > N ? 0 : coins(id, sum+denom[id]);
		dp[id][sum] = a + b;
	}
	return dp[id][sum];
}

int main()
{
	while (cin >> N)
	{
		LL M = coins(0, 0);	
		if (M == 1)
			printf("There is only %lld way to produce %d cents change.\n", M, N);
		else 
			printf("There are %lld ways to produce %d cents change.\n", M, N);
	}
}
