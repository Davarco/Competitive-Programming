#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

LL gcd(LL a, LL b)
{
	return a % b == 0 ? b : gcd(b, a % b);
}

int main()
{
	LL X;
	cin >> X; 

	LL best = X;
	for (LL x = 2; x <= sqrt(X); x++)
		if (X % x == 0 && gcd(X/x, x) == 1)
			best = min(best, X/x);
	printf("%lld %lld\n", X/best, best);
}

