#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

LL mod = 1000000007;

LL N;
string S;

LL mpow(LL a, LL b)
{
	LL ret = 1;
	for (LL i = 0; i < b; i++)
		ret = (ret*a) % mod;
	return ret;
}

int main()
{
	cin >> S;
	N = S.size();

	LL m = 1, a = 0, b = 0, c = 0;
	for (int n = 0; n < N; n++)
	{
		if (S[n] == 'A')
			a += m;
		if (S[n] == 'B')
			b += a;
		if (S[n] == 'C')
			c += b;
		if (S[n] == '?')
		{
			c = 3*c + b;
			b = 3*b + a;
			a = 3*a + m;
			m *= 3;
		}
		a %= mod, b %= mod, c %= mod, m %= mod;
	}
	cout << (c % mod) << endl;
}

